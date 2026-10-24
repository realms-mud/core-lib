//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/support/guilds/monkTrialFixture.c";

object User;
object Lian;
object Ren;
object Sora;
object Iori;
object Room;
object Weapon;
object *ExtraWeapons;
int StudentNumber;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    load_object("/guilds/monk/monk.c");
    ignoreList += ({ "PrepareMaster", "LearnPath", "AdvanceTo",
        "RecoverAction", "EquipWeapon", "TeachMonkTrialLesson",
        "CompleteMonkUpperTrial" });
    Room = clone_object("/lib/environment/environment.c");
    Lian = clone_object("/guilds/monk/teachers/lian.c");
    Ren = clone_object("/guilds/monk/teachers/ren.c");
    Sora = clone_object("/guilds/monk/teachers/sora.c");
    Iori = clone_object("/guilds/monk/teachers/iori.c");
    foreach(object teacher in ({ Lian, Ren, Sora, Iori }))
    {
        move_object(teacher, Room);
    }
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    foreach(object teacher in ({ Lian, Ren, Sora, Iori }))
    {
        move_object(teacher, Room);
    }
    ExtraWeapons = ({});
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name(sprintf("catalogue%d", ++StudentNumber));
    User.Str(20);
    User.Int(20);
    User.Dex(20);
    User.Con(20);
    User.Wis(20);
    User.Chr(20);
    User.colorConfiguration("none");
    Weapon = clone_object("/lib/items/weapon.c");
    Weapon.set("blueprint", "katana");
    Weapon.set("name", "katana");
    move_object(User, Room);
    move_object(Weapon, User);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    foreach(object item in ExtraWeapons)
    {
        if (objectp(item))
        {
            destruct(item);
        }
    }
    destruct(Weapon);
    destruct(User);
}

/////////////////////////////////////////////////////////////////////////////
void TearDown()
{
    destruct(Ren);
    destruct(Sora);
    destruct(Iori);
    destruct(Lian);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceTo(int level)
{
    int advancing = 1;
    while (advancing && User.guildLevel("monk") < level)
    {
        User.addExperience(User.experienceToNextLevel("monk"), "monk");
        advancing = User.advanceLevel("monk");
    }
    ExpectEq(level, User.guildLevel("monk"));
}

/////////////////////////////////////////////////////////////////////////////
void PrepareMaster()
{
    ExpectTrue(User.joinGuild("monk"));
    User.addResearchPoints(1000);
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/initiates-discipline.c"));
    string *foundations = ({ "disciplined-breath", "students-awareness",
        "disciples-insight", "adepts-focus", "inner-discipline",
        "mastery-of-fundamentals" });
    for (int index = 0; index < sizeof(foundations); index++)
    {
        AdvanceTo(MonkPromotionLevels[index]);
        ExpectTrue(User.initiateResearch("/guilds/monk/discipline/" +
            foundations[index] + ".c"));
        if (index == 2)
        {
            for (int use = 0; use < 10; use++)
            {
                ExpectTrue(mappingp(User.recordObservation(([
                    "type":"combat.kata",
                    "context":([
                        "research":"/guilds/monk/unarmed/measured-palm.c",
                        "qualifying opponent":1
                    ])
                ]), 1)));
            }
            ExpectTrue(User.learnResearchFrom(Ren,
                "/guilds/monk/discipline/adepts-trial.c"));
        }
        if (index >= 3)
        {
            CompleteMonkUpperTrial(User, Lian, Ren, index - 3);
        }
        ExpectTrue(User.advanceRank("monk"));
        if (index == 0)
        {
            ExpectTrue(User.learnResearchFrom(Lian,
                "/guilds/monk/discipline/steady-practice.c"));
            ExpectTrue(User.learnResearchFrom(Lian,
                "/guilds/monk/discipline/teachers-recognition.c"));
        }
    }
    ExpectEq("master", User.guildRank("monk"));
}

/////////////////////////////////////////////////////////////////////////////
void LearnPath(string discipline, string name)
{
    string path = "/guilds/monk/" + discipline + "/" + name + ".c";
    TeachMonkTrialLesson(User, ({ Lian, Ren, Sora }), path);
}

/////////////////////////////////////////////////////////////////////////////
void RecoverAction(object opponent)
{
    if (opponent)
    {
        User.stopFight(opponent);
        opponent.stopFight(User);
    }
    for (int tick = 0; tick < 16; tick++)
    {
        User.heart_beat();
    }
    User.staminaPoints(10000);
    User.spellPoints(10000);
}

/////////////////////////////////////////////////////////////////////////////
object EquipWeapon(string name, string blueprint, int offhand)
{
    object item = clone_object("/lib/items/weapon.c");
    item.set("blueprint", blueprint);
    item.set("name", name);
    move_object(item, User);
    ExtraWeapons += ({ item });
    ExpectTrue(item.equip(name + (offhand ? " offhand" : "")),
        "Equipping " + name);
    return item;
}

/////////////////////////////////////////////////////////////////////////////
void AllTenCatalogsHaveUniqueTaughtLessonsAndCommands()
{
    mapping names = ([]);
    mapping commands = ([]);
    foreach(string discipline in ({ "unarmed", "katana", "bludgeon",
        "pure-chi", "mana-shield", "paired-swords", "odachi", "archery",
        "kama", "claw" }))
    {
        object tree = getService("research")->researchTree(
            "/guilds/monk/" + discipline + ".c");
        ExpectEq(41, sizeof(tree->getFlattenedResearchTree()));
        foreach(object item in m_indices(tree->getFlattenedResearchTree()))
        {
            if (item->query("research type") != "tree root")
            {
                string path = program_name(item);
                string name = lower_case(item->query("name"));
                ExpectFalse(member(names, name),
                    sprintf("Duplicate lesson %s: %O and %s",
                        name, names[name], path));
                names[name] = path;
                ExpectTrue(Lian.teachesResearch(path) ||
                    Ren.teachesResearch(path) ||
                    Sora.teachesResearch(path) ||
                    Iori.teachesResearch(path), path);
                string command = item->query("command template");
                if (command)
                {
                    ExpectFalse(member(commands, command),
                        sprintf("Duplicate command %s: %O and %s",
                            command, commands[command], path));
                    commands[command] = path;
                }
            }
        }
    }
    ExpectEq(400, sizeof(names));
}

/////////////////////////////////////////////////////////////////////////////
void ExpandedLessonsRequireRecognitionAndOpenBeforeStudentRank()
{
    string lesson = "/guilds/monk/unarmed/quiet-footwork.c";
    ExpectTrue(User.joinGuild("monk"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/initiates-discipline.c"));
    AdvanceTo(5);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectFalse(User.advanceRank("monk"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/unarmed/measured-palm.c"));
    int points = User.researchPoints();
    int respect = Ren.relationshipValue(User, "respect");
    ExpectFalse(User.learnResearchFrom(Ren, lesson));
    ExpectEq(points, User.researchPoints());
    ExpectEq(respect, Ren.relationshipValue(User, "respect"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/steady-practice.c"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/teachers-recognition.c"));
    ExpectTrue(User.learnResearchFrom(Ren, lesson));
    ExpectEq("initiate", User.guildRank("monk"));
    ExpectEq(5, User.guildLevel("monk"));
}

/////////////////////////////////////////////////////////////////////////////
void BothTreesHaveFortyNonRootItemsAndMixedResearchTypes()
{
    foreach(string discipline in ({ "unarmed", "katana" }))
    {
        object tree = getService("research")->researchTree(
            "/guilds/monk/" + discipline + ".c");
        mapping items = tree->getFlattenedResearchTree();
        ExpectEq(41, sizeof(items));
        mapping counts = ([]);
        foreach(object item in m_indices(items))
        {
            if (item->query("research type") != "tree root")
            {
                string type = item->query("type");
                counts[type]++;
                ExpectTrue(item->isValidResearchItem());
                ExpectTrue(item->query("teacher required"));
                ExpectTrue(item->query("research cost") > 0);
                ExpectTrue(sizeof(item->query("description")) > 20);
                ExpectFalse(item->checkPrerequisites(User));
                ExpectTrue(sizeof(tree->getParents(program_name(item))) > 0);
            }
        }
        ExpectTrue(counts["passive"] >= 12);
        ExpectEq(12, counts["knowledge"]);
        ExpectEq(4, counts["sustained"]);
        ExpectTrue(counts["active"] >= 10);
    }
}

/////////////////////////////////////////////////////////////////////////////
void EveryMartialCatalogItemIsReachableThroughItsTeacherAndDependencies()
{
    PrepareMaster();
    foreach(string discipline in ({
        "unarmed", "katana", "paired-swords", "odachi", "kama", "claw" }))
    {
        object tree = getService("research")->researchTree(
            "/guilds/monk/" + discipline + ".c");
        foreach(object item in m_indices(tree->getFlattenedResearchTree()))
        {
            string name = regreplace(program_name(item),
                "^.*/([^/]+).c$", "\\1");
            LearnPath(discipline, name);
            ExpectTrue(User.isResearched(program_name(item)));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void KnowledgeActuallyChangesDamageCostsAndCooldowns()
{
    ExpectTrue(User.joinGuild("monk"));
    AdvanceTo(10);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(User.advanceRank("monk"));
    User.addResearchPoints(100);
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/initiates-discipline.c"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/steady-practice.c"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/teachers-recognition.c"));
    LearnPath("unarmed", "driving-elbow");
    object elbow = load_object("/guilds/monk/unarmed/driving-elbow.c");
    int before = elbow.getEffectsToApply(User)["effects"]["damage hit points"];
    LearnPath("unarmed", "elbow-anatomy");
    ExpectEq(before + 3,
        elbow.getEffectsToApply(User)["effects"]["damage hit points"]);
}

/////////////////////////////////////////////////////////////////////////////
void KnowledgeActuallyChangesCostsAndCooldowns()
{
    PrepareMaster();
    LearnPath("katana", "quick-draw");
    object draw = load_object("/guilds/monk/katana/quick-draw.c");
    ExpectEq(6, draw.getUsageCosts("", User)["stamina point cost"]);
    LearnPath("katana", "draw-economy");
    ExpectEq(5, draw.getUsageCosts("", User)["stamina point cost"]);
    LearnPath("katana", "decisive-cut");
    object cut = load_object("/guilds/monk/katana/decisive-cut.c");
    ExpectEq(18, cut.cooldown(User));
    LearnPath("katana", "decisive-rhythm");
    ExpectEq(14, cut.cooldown(User));
}

/////////////////////////////////////////////////////////////////////////////
void PassiveBonusesTrackCurrentEquipment()
{
    PrepareMaster();
    int dodge = User.researchBonusTo("dodge");
    LearnPath("unarmed", "quiet-footwork");
    ExpectEq(dodge + 1, User.researchBonusTo("dodge"));
    int unarmedParry = User.researchBonusTo("parry");
    ExpectTrue(Weapon.equip("katana"));
    ExpectEq(dodge, User.researchBonusTo("dodge"));
    int parry = User.researchBonusTo("parry");
    LearnPath("katana", "traveling-guard");
    ExpectEq(parry + 1, User.researchBonusTo("parry"));
    ExpectTrue(Weapon.unequip("katana"));
    ExpectEq(unarmedParry, User.researchBonusTo("parry"));
}

/////////////////////////////////////////////////////////////////////////////
void SustainedFormsReserveResourcesAndCanBeReleasedAfterEquipmentChanges()
{
    PrepareMaster();
    User.addSkillPoints(100);
    ExpectTrue(User.advanceSkill("dodge", 1));
    ExpectTrue(User.advanceSkill("parry", 1));
    int unarmedParry = User.getSkill("parry");
    LearnPath("unarmed", "crane-stance");
    int maximum = User.maxStaminaPoints();
    int dodge = User.getSkill("dodge");
    ExpectTrue(User.researchCommand("kata crane stance"));
    ExpectEq(maximum - 8, User.maxStaminaPoints());
    ExpectEq(dodge + 3, User.getSkill("dodge"));
    for (int tick = 0; tick < 4; tick++)
    {
        User.heart_beat();
    }
    ExpectTrue(Weapon.equip("katana"));
    ExpectEq(dodge - 1, User.getSkill("dodge"));
    ExpectFalse(User.researchCommand("kata crane stance"));
    ExpectFalse(User.sustainedResearchIsActive(
        "/guilds/monk/unarmed/crane-stance.c"));
    ExpectEq(maximum, User.maxStaminaPoints());
    LearnPath("katana", "high-guard");
    int parry = User.getSkill("parry");
    ExpectTrue(User.researchCommand("kata high guard"));
    ExpectEq(maximum - 8, User.maxStaminaPoints());
    ExpectEq(parry + 3, User.getSkill("parry"));
    for (int tick = 0; tick < 4; tick++)
    {
        User.heart_beat();
    }
    object replacement = clone_object("/lib/items/weapon.c");
    replacement.set("blueprint", "katana");
    replacement.set("name", "replacement");
    move_object(replacement, User);
    ExpectTrue(replacement.equip("replacement"));
    ExpectTrue(User.sustainedResearchIsActive(
        "/guilds/monk/katana/high-guard.c"));
    ExpectEq(maximum - 8, User.maxStaminaPoints());
    ExpectEq(parry + 3, User.getSkill("parry"));
    ExpectTrue(User.unequip(replacement));
    ExpectEq(unarmedParry, User.getSkill("parry"));
    ExpectFalse(User.researchCommand("kata high guard"));
    ExpectEq(maximum, User.maxStaminaPoints());
    destruct(replacement);
}

/////////////////////////////////////////////////////////////////////////////
void NewAttacksUseNormalDamageAndDrainOpponentResources()
{
    PrepareMaster();
    LearnPath("unarmed", "driving-elbow");
    LearnPath("unarmed", "disrupting-knee");
    object target = clone_object("/lib/realizations/npc.c");
    target.Name("opponent");
    target.effectiveLevel(16);
    target.setMaxHitPoints(10000);
    target.setMaxStaminaPoints(1000);
    target.staminaPoints(1000);
    move_object(target, Room);
    User.staminaPoints(10000);
    int stamina = User.staminaPoints();
    int health = target.hitPoints();
    ExpectTrue(User.researchCommand("kata driving elbow at opponent"));
    ExpectTrue(target.hitPoints() < health);
    ExpectEq(stamina - 8, User.staminaPoints());
    User.stopFight(target);
    target.stopFight(User);
    for (int tick = 0; tick < 5; tick++)
    {
        User.heart_beat();
    }
    int reserve = target.staminaPoints();
    health = target.hitPoints();
    ExpectTrue(User.researchCommand("kata disrupting knee at opponent"));
    ExpectTrue(target.staminaPoints() < reserve);
    ExpectEq(health, target.hitPoints());
    destruct(target);
}

/////////////////////////////////////////////////////////////////////////////
void SoraCatalogsHaveFortyNonRootItemsWithExecutableKnowledge()
{
    foreach(string discipline in ({ "paired-swords", "odachi",
        "kama", "claw" }))
    {
        object tree = getService("research")->researchTree(
            "/guilds/monk/" + discipline + ".c");
        mapping counts = ([]);
        mapping names = ([]);
        mapping items = tree->getFlattenedResearchTree();
        ExpectEq(41, sizeof(items));
        foreach(object item in m_indices(items))
        {
            names[item->query("name")] = item;
            if (item->query("research type") != "tree root")
            {
                counts[item->query("type")]++;
                ExpectTrue(item->isValidResearchItem());
                ExpectTrue(item->query("teacher required"));
                ExpectTrue(item->query("research cost") > 0);
                ExpectTrue(sizeof(item->query("description")) > 20);
                ExpectTrue(sizeof(tree->getParents(program_name(item))) > 0);
                ExpectFalse(item->checkPrerequisites(User));
                ExpectTrue(Sora.teachesResearch(program_name(item)));
                ExpectFalse(Ren.teachesResearch(program_name(item)));
                ExpectFalse(Lian.teachesResearch(program_name(item)));
            }
        }
        ExpectEq(12, counts["knowledge"]);
        ExpectEq(12, counts["passive"]);
        ExpectEq(12, counts["active"]);
        ExpectEq(4, counts["sustained"]);
        foreach(object item in m_indices(items))
        {
            if (item->query("type") == "knowledge" &&
                item->query("research type") != "tree root")
            {
                mapping affected = item->query("affected research");
                ExpectTrue(sizeof(affected) >= 1);
                foreach(string name in m_indices(affected))
                {
                    object receiver = names[name];
                    ExpectTrue(objectp(receiver), name);
                    if (receiver)
                    {
                        int wired = 0;
                        string path = program_name(item);
                        mixed modifiers = receiver->query("modifiers");
                        if (pointerp(modifiers))
                        {
                            foreach(mapping modifier in modifiers)
                            {
                                if (modifier["type"] == "research" &&
                                    modifier["research item"] == path &&
                                    modifier["base value"] == 1 &&
                                    modifier["formula"] == "additive" &&
                                    modifier["rate"] ==
                                        to_float(affected[name]))
                                {
                                    wired = 1;
                                }
                            }
                        }
                        foreach(string key in ({
                            "stamina point cost modifiers",
                            "cooldown modifiers" }))
                        {
                            mixed reductions = receiver->query(key);
                            if (mappingp(reductions) &&
                                member(reductions, path) &&
                                reductions[path] == affected[name])
                            {
                                wired = 1;
                            }
                        }
                        ExpectTrue(wired, path);
                    }
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void SwordTreesOpenAtOneAndAdvancedTeachingRequiresRecognition()
{
    string grip = "/guilds/monk/paired-swords/companion-grip.c";
    ExpectTrue(User.joinGuild("monk"));
    ExpectTrue(User.isResearched("/guilds/monk/paired-swords/root.c"));
    ExpectTrue(User.isResearched("/guilds/monk/odachi/root.c"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/initiates-discipline.c"));
    AdvanceTo(10);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(User.advanceRank("monk"));
    AdvanceTo(19);
    ExpectTrue(User.isResearched("/guilds/monk/paired-swords/root.c"));
    ExpectTrue(User.isResearched("/guilds/monk/odachi/root.c"));
    AdvanceTo(20);
    ExpectTrue(User.isResearched("/guilds/monk/paired-swords/root.c"));
    ExpectTrue(User.isResearched("/guilds/monk/odachi/root.c"));
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/students-awareness.c"));
    ExpectTrue(User.advanceRank("monk"));
    ExpectTrue(User.learnResearchFrom(Sora,
        "/guilds/monk/paired-swords/linked-cut.c"));
    ExpectTrue(User.learnResearchFrom(Sora,
        "/guilds/monk/paired-swords/paired-grip.c"));
    int points = User.researchPoints();
    ExpectFalse(User.learnResearchFrom(Sora, grip));
    ExpectEq(points, User.researchPoints());
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/steady-practice.c"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/teachers-recognition.c"));
    ExpectFalse(User.initiateResearch(grip));
    ExpectFalse(User.learnResearchFrom(Ren, grip));
    ExpectTrue(User.learnResearchFrom(Sora, grip));
    points = User.researchPoints();
    int respect = Sora.relationshipValue(User, "respect");
    ExpectFalse(User.learnResearchFrom(Sora, grip));
    ExpectEq(points, User.researchPoints());
    ExpectEq(respect, Sora.relationshipValue(User, "respect"));
    move_object(Sora, this_object());
    ExpectFalse(User.learnResearchFrom(Sora,
        "/guilds/monk/paired-swords/paired-guard.c"));
    ExpectEq(points, User.researchPoints());
}

/////////////////////////////////////////////////////////////////////////////
void PairedStyleRequiresBothExactBlueprintsInTheirCorrectSlots()
{
    PrepareMaster();
    LearnPath("paired-swords", "linked-cut");
    LearnPath("paired-swords", "companion-grip");
    int baseline = User.researchBonusTo("short sword");
    object cut = load_object("/guilds/monk/paired-swords/linked-cut.c");
    ExpectFalse(cut.canApplySpecification("", User));
    ExpectTrue(Weapon.equip("katana"));
    ExpectFalse(cut.canApplySpecification("", User));
    object companion = EquipWeapon("companion", "wakisashi", 1);
    ExpectTrue(cut.canApplySpecification("", User));
    ExpectEq(baseline + 1, User.researchBonusTo("short sword"));
    object wrong = EquipWeapon("shortblade", "short sword", 1);
    ExpectEq("short sword", wrong.query("weapon type"));
    ExpectFalse(cut.canApplySpecification("", User));
    ExpectEq(baseline, User.researchBonusTo("short sword"));
    ExpectTrue(wrong.unequip("shortblade"));
    ExpectFalse(cut.canApplySpecification("", User));
    ExpectTrue(companion.equip("companion offhand"));
    EquipWeapon("longblade", "bastard sword", 0);
    ExpectFalse(cut.canApplySpecification("", User));
    ExpectTrue(Weapon.equip("katana"));
    ExpectTrue(cut.canApplySpecification("", User));
    EquipWeapon("reversed", "wakisashi", 0);
    EquipWeapon("otherkatana", "katana", 1);
    ExpectFalse(cut.canApplySpecification("", User));
    ExpectEq(baseline, User.researchBonusTo("short sword"));
}

/////////////////////////////////////////////////////////////////////////////
void OdachiStyleRejectsSameSkillSwordsAndNormalOffhandReplacement()
{
    PrepareMaster();
    LearnPath("odachi", "committed-cut");
    LearnPath("odachi", "longblade-grip");
    int baseline = User.researchBonusTo("two-handed sword");
    object cut = load_object("/guilds/monk/odachi/committed-cut.c");
    object odachi = EquipWeapon("odachi", "odachi", 0);
    ExpectTrue(cut.canApplySpecification("", User));
    ExpectEq(baseline + 1, User.researchBonusTo("two-handed sword"));
    ExpectEq(odachi, User.equipmentInSlot("wielded primary"));
    ExpectEq(odachi, User.equipmentInSlot("wielded offhand"));
    object other = EquipWeapon("claymore", "claymore", 0);
    ExpectEq("two-handed sword", other.query("weapon type"));
    ExpectFalse(cut.canApplySpecification("", User));
    ExpectEq(baseline, User.researchBonusTo("two-handed sword"));
    ExpectTrue(odachi.equip("odachi"));
    EquipWeapon("dagger", "dagger", 1);
    ExpectFalse(User.isEquipped(odachi));
    ExpectFalse(cut.canApplySpecification("", User));
}

/////////////////////////////////////////////////////////////////////////////
void SwordKnowledgeChangesActualDamageCostsAndCooldowns()
{
    PrepareMaster();
    LearnPath("paired-swords", "linked-cut");
    ExpectTrue(Weapon.equip("katana"));
    EquipWeapon("companion", "wakisashi", 1);
    object linked = load_object("/guilds/monk/paired-swords/linked-cut.c");
    int damage = linked.getEffectsToApply(User)["effects"]["damage hit points"];
    LearnPath("paired-swords", "linked-lines");
    ExpectEq(damage + 3,
        linked.getEffectsToApply(User)["effects"]["damage hit points"]);
    LearnPath("paired-swords", "breath-shear");
    object breath = load_object("/guilds/monk/paired-swords/breath-shear.c");
    ExpectEq(10, breath.getUsageCosts("", User)["stamina point cost"]);
    LearnPath("paired-swords", "paired-breath-economy");
    ExpectEq(8, breath.getUsageCosts("", User)["stamina point cost"]);
    LearnPath("paired-swords", "returning-cut");
    object returning = load_object("/guilds/monk/paired-swords/returning-cut.c");
    ExpectEq(22, returning.cooldown(User));
    LearnPath("paired-swords", "paired-return-rhythm");
    ExpectEq(18, returning.cooldown(User));
    LearnPath("odachi", "committed-cut");
    EquipWeapon("odachi", "odachi", 0);
    object committed = load_object("/guilds/monk/odachi/committed-cut.c");
    damage = committed.getEffectsToApply(User)["effects"]["damage hit points"];
    LearnPath("odachi", "commitment-theory");
    ExpectEq(damage + 3,
        committed.getEffectsToApply(User)["effects"]["damage hit points"]);
    ExpectEq(14, committed.getUsageCosts("", User)["stamina point cost"]);
    LearnPath("odachi", "longblade-economy");
    ExpectEq(12, committed.getUsageCosts("", User)["stamina point cost"]);
    LearnPath("odachi", "horizon-cut");
    object horizon = load_object("/guilds/monk/odachi/horizon-cut.c");
    ExpectEq(22, horizon.cooldown(User));
    LearnPath("odachi", "horizon-rhythm");
    ExpectEq(18, horizon.cooldown(User));
}

/////////////////////////////////////////////////////////////////////////////
void SwordFormsReserveResourcesAndEndWhenEitherStyleBecomesInvalid()
{
    PrepareMaster();
    User.addSkillPoints(200);
    ExpectTrue(User.advanceSkill("parry", 1));
    LearnPath("paired-swords", "paired-high-guard");
    ExpectTrue(Weapon.equip("katana"));
    object companion = EquipWeapon("companion", "wakisashi", 1);
    int maximum = User.maxStaminaPoints();
    int parry = User.getSkill("parry");
    ExpectTrue(User.researchCommand("kata paired high guard"),
        "Activating paired high guard");
    ExpectEq(maximum - 10, User.maxStaminaPoints());
    ExpectEq(parry + 3, User.getSkill("parry"));
    RecoverAction(0);
    EquipWeapon("replacement", "wakisashi", 1);
    ExpectTrue(User.sustainedResearchIsActive(
        "/guilds/monk/paired-swords/paired-high-guard.c"),
        "Keeping the guard after an eligible offhand replacement");
    ExpectEq(maximum - 10, User.maxStaminaPoints());
    EquipWeapon("wrongcompanion", "short sword", 1);
    ExpectFalse(User.sustainedResearchIsActive(
        "/guilds/monk/paired-swords/paired-high-guard.c"));
    ExpectEq(maximum, User.maxStaminaPoints());
    ExpectEq(parry - 1, User.getSkill("parry"));
    ExpectTrue(companion.equip("companion offhand"),
        "Restoring the original offhand companion");
    ExpectFalse(User.researchCommand("kata paired high guard"));
    User.heart_beat();
    ExpectFalse(User.researchCommand("kata paired high guard"));
    User.heart_beat();
    ExpectTrue(User.researchCommand("kata paired high guard"),
        "Reactivating paired high guard");
    RecoverAction(0);
    EquipWeapon("wrongprimary", "bastard sword", 0);
    ExpectFalse(User.sustainedResearchIsActive(
        "/guilds/monk/paired-swords/paired-high-guard.c"));
    ExpectEq(maximum, User.maxStaminaPoints());
    LearnPath("odachi", "horizon-guard");
    EquipWeapon("odachi", "odachi", 0);
    parry = User.getSkill("parry");
    ExpectTrue(User.researchCommand("kata horizon guard"),
        "Activating horizon guard");
    ExpectEq(maximum - 12, User.maxStaminaPoints());
    ExpectEq(parry + 3, User.getSkill("parry"));
    RecoverAction(0);
    EquipWeapon("claymore", "claymore", 0);
    ExpectFalse(User.sustainedResearchIsActive(
        "/guilds/monk/odachi/horizon-guard.c"));
    ExpectEq(maximum, User.maxStaminaPoints());
    ExpectEq(parry - 1, User.getSkill("parry"));
}

/////////////////////////////////////////////////////////////////////////////
void PairedAttackUsesBothWeaponsAndOneNormalCostCooldownAndObservation()
{
    PrepareMaster();
    User.addSkillPoints(200);
    ExpectTrue(User.advanceSkill("hand and a half sword", 1));
    ExpectTrue(User.advanceSkill("short sword", 1));
    LearnPath("paired-swords", "linked-cut");
    LearnPath("paired-swords", "companion-check");
    ExpectTrue(Weapon.equip("katana"));
    object companion = EquipWeapon("companion", "wakisashi", 1);
    object linked = load_object("/guilds/monk/paired-swords/linked-cut.c");
    int damage = linked.getEffectsToApply(User)["effects"]["damage hit points"];
    ExpectTrue(companion.unequip("companion"));
    companion.set("weapon class", 60);
    ExpectTrue(companion.equip("companion offhand"));
    ExpectTrue(linked.getEffectsToApply(User)["effects"]["damage hit points"]
        > damage);
    damage = linked.getEffectsToApply(User)["effects"]["damage hit points"];
    ExpectTrue(Weapon.unequip("katana"));
    Weapon.set("weapon class", 60);
    ExpectTrue(Weapon.equip("katana"));
    ExpectTrue(linked.getEffectsToApply(User)["effects"]["damage hit points"]
        > damage);
    object target = clone_object("/lib/realizations/npc.c");
    target.Name("opponent");
    target.effectiveLevel(16);
    target.setMaxHitPoints(10000);
    target.setMaxStaminaPoints(1000);
    target.staminaPoints(1000);
    move_object(target, Room);
    RecoverAction(target);
    int stamina = User.staminaPoints();
    int health = target.hitPoints();
    ExpectTrue(User.researchCommand("kata linked cut at opponent"));
    ExpectEq(stamina - 10, User.staminaPoints());
    ExpectTrue(target.hitPoints() < health);
    ExpectEq(1, User.countObservations(([
        "type":"combat.kata",
        "research":"/guilds/monk/paired-swords/linked-cut.c"
    ])));
    health = target.hitPoints();
    ExpectFalse(User.researchCommand("kata linked cut at opponent"));
    ExpectEq(health, target.hitPoints());
    ExpectEq(stamina - 10, User.staminaPoints());
    RecoverAction(target);
    health = target.hitPoints();
    stamina = target.staminaPoints();
    ExpectTrue(User.researchCommand("kata companion check at opponent"));
    ExpectTrue(target.staminaPoints() < stamina);
    ExpectEq(health, target.hitPoints());
    RecoverAction(target);
    ExpectTrue(companion.unequip("companion"));
    stamina = User.staminaPoints();
    ExpectFalse(User.researchCommand("kata linked cut at opponent"));
    ExpectEq(stamina, User.staminaPoints());
    ExpectEq(1, User.countObservations(([
        "type":"combat.kata",
        "research":"/guilds/monk/paired-swords/linked-cut.c"
    ])));
    destruct(target);
}

/////////////////////////////////////////////////////////////////////////////
void ShortBladeRootsOpenAtOneAndAdvancedTeachingRequiresRecognition()
{
    ExpectTrue(User.joinGuild("monk"));
    ExpectTrue(User.isResearched("/guilds/monk/kama/root.c"));
    ExpectTrue(User.isResearched("/guilds/monk/claw/root.c"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/initiates-discipline.c"));
    AdvanceTo(10);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(User.advanceRank("monk"));
    AdvanceTo(19);
    foreach(string discipline in ({ "kama", "claw" }))
    {
        ExpectTrue(User.isResearched("/guilds/monk/" +
            discipline + "/root.c"));
    }
    AdvanceTo(20);
    foreach(string discipline in ({ "kama", "claw" }))
    {
        ExpectTrue(User.isResearched("/guilds/monk/" +
            discipline + "/root.c"));
        ExpectTrue(member(User.availableResearchTrees(),
            "/guilds/monk/" + discipline + ".c") >= 0);
    }
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/students-awareness.c"));
    ExpectTrue(User.advanceRank("monk"));
    ExpectTrue(User.learnResearchFrom(Sora,
        "/guilds/monk/kama/measured-hook.c"));
    ExpectTrue(User.learnResearchFrom(Sora,
        "/guilds/monk/claw/measured-rake.c"));
    string grip = "/guilds/monk/kama/hook-geometry.c";
    int points = User.researchPoints();
    ExpectFalse(User.learnResearchFrom(Sora, grip));
    ExpectEq(points, User.researchPoints());
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/steady-practice.c"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/teachers-recognition.c"));
    foreach(string path in ({ grip, "/guilds/monk/claw/rake-geometry.c" }))
    {
        ExpectFalse(User.initiateResearch(path));
        ExpectFalse(User.learnResearchFrom(Ren, path));
        move_object(Sora, this_object());
        ExpectFalse(User.learnResearchFrom(Sora, path));
        move_object(Sora, Room);
        ExpectTrue(User.learnResearchFrom(Sora, path));
        points = User.researchPoints();
        int respect = Sora.relationshipValue(User, "respect");
        ExpectFalse(User.learnResearchFrom(Sora, path));
        ExpectEq(points, User.researchPoints());
        ExpectEq(respect, Sora.relationshipValue(User, "respect"));
    }
    ExpectTrue(User.leaveGuild("monk"));
    ExpectFalse(User.learnResearchFrom(Sora,
        "/guilds/monk/kama/sickle-distance.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ShortBladesRequireExactPrimaryBlueprintsNotTheirSharedSkills()
{
    PrepareMaster();
    foreach(string discipline in ({ "kama", "claw" }))
    {
        string blueprint = discipline == "kama" ? "kama" : "tiger claws";
        string skill = discipline == "kama" ? "short sword" : "dagger";
        string name = "implement" + discipline;
        string basic = discipline == "kama" ? "measured-hook" :
            "measured-rake";
        LearnPath(discipline, basic);
        LearnPath(discipline, discipline == "kama" ?
            "hooked-grip" : "claw-grip");
        object ability = load_object("/guilds/monk/" + discipline +
            "/" + basic + ".c");
        int baseline = User.researchBonusTo(skill);
        ExpectFalse(ability.canApplySpecification("", User));
        object implement = EquipWeapon(name, blueprint, 1);
        ExpectFalse(ability.canApplySpecification("", User));
        ExpectEq(baseline, User.researchBonusTo(skill));
        ExpectTrue(implement.unequip(name));
        ExpectTrue(implement.equip(name));
        ExpectTrue(ability.canApplySpecification("", User));
        ExpectEq(baseline + 1, User.researchBonusTo(skill));
        EquipWeapon("companion" + discipline, "dagger", 1);
        ExpectTrue(ability.canApplySpecification("", User));
        object wrong = EquipWeapon("wrong" + discipline, skill, 0);
        ExpectEq(skill, wrong.query("weapon type"));
        ExpectFalse(ability.canApplySpecification("", User));
        ExpectEq(baseline, User.researchBonusTo(skill));
    }
}

/////////////////////////////////////////////////////////////////////////////
void ShortBladeKnowledgeChangesActualDamageCostsAndCooldowns()
{
    PrepareMaster();
    foreach(string discipline in ({ "kama", "claw" }))
    {
        int kama = discipline == "kama";
        string base = "/guilds/monk/" + discipline + "/";
        string basic = kama ? "measured-hook" : "measured-rake";
        LearnPath(discipline, basic);
        EquipWeapon("implement" + discipline, kama ? "kama" : "tiger claws",
            0);
        object ability = load_object(base + basic + ".c");
        int damage = ability.getEffectsToApply(User)
            ["effects"]["damage hit points"];
        LearnPath(discipline, kama ? "hook-geometry" : "rake-geometry");
        ExpectEq(damage + 3, ability.getEffectsToApply(User)
            ["effects"]["damage hit points"]);
        ExpectEq(8, ability.getUsageCosts("", User)["stamina point cost"]);
        LearnPath(discipline, kama ? "hook-economy" : "rake-economy");
        ExpectEq(6, ability.getUsageCosts("", User)["stamina point cost"]);
        string middle = kama ? "reaping-cut" : "crossing-rake";
        LearnPath(discipline, middle);
        ability = load_object(base + middle + ".c");
        ExpectEq(kama ? 16 : 14, ability.cooldown(User));
        LearnPath(discipline, kama ? "reaping-rhythm" : "crossing-rhythm");
        ExpectEq(kama ? 12 : 10, ability.cooldown(User));
        string finalAttack = kama ? "final-reap" : "final-rake";
        LearnPath(discipline, finalAttack);
        ability = load_object(base + finalAttack + ".c");
        ExpectEq(kama ? 22 : 20,
            ability.getUsageCosts("", User)["stamina point cost"]);
        LearnPath(discipline, kama ? "final-reap-economy" :
            "final-rake-economy");
        ExpectEq(kama ? 19 : 17,
            ability.getUsageCosts("", User)["stamina point cost"]);
    }
}

/////////////////////////////////////////////////////////////////////////////
void AllTwentyTwoShortBladeAttacksApplyOneEffectCostAndObservation()
{
    PrepareMaster();
    object foe = clone_object("/lib/realizations/npc.c");
    foe.Name("opponent");
    foe.effectiveLevel(35);
    foe.setMaxHitPoints(10000);
    move_object(foe, Room);
    mapping catalogs = ([
        "kama":({ "measured-hook", "sickle-check", "reaping-cut",
            "breath-hook", "binding-hook", "crescent-reap", "sickle-point",
            "returning-hook", "tiring-reap", "final-reap", "quiet-hook" }),
        "claw":({ "measured-rake", "claw-check", "crossing-rake",
            "breath-rake", "gripping-rake", "rising-talon", "talon-point",
            "returning-rake", "tiring-rake", "final-rake", "quiet-rake" })
    ]);
    foreach(string discipline, string *attacks in catalogs)
    {
        RecoverAction(foe);
        EquipWeapon("implement" + discipline,
            discipline == "kama" ? "kama" : "tiger claws", 0);
        foreach(string name in attacks)
        {
            LearnPath(discipline, name);
            RecoverAction(foe);
            foe.staminaPoints(10000);
            foe.spellPoints(10000);
            ExpectTrue(foe.registerAttacker(User));
            ExpectTrue(User.registerAttacker(foe));
            string path = "/guilds/monk/" + discipline + "/" + name + ".c";
            object ability = load_object(path);
            int stamina = User.staminaPoints();
            int health = foe.hitPoints();
            int targetStamina = foe.staminaPoints();
            int targetSpellPoints = foe.spellPoints();
            int cost = ability.getUsageCosts("", User)["stamina point cost"];
            ExpectFalse(ability.query("consumables"));
            ExpectEq(discipline == "claw" || name == "sickle-point" ?
                "thrust" : "slash", ability.query("damage type"));
            string command = regreplace(ability.query("command template"),
                "##Target##", "opponent");
            ExpectTrue(User.executeCommand(command), path);
            ExpectEq(stamina - cost, User.staminaPoints(), path);
            if (ability.query("damage hit points"))
            {
                ExpectTrue(foe.hitPoints() < health, path);
            }
            else if (ability.query("damage stamina points"))
            {
                ExpectTrue(foe.staminaPoints() < targetStamina, path);
            }
            else
            {
                ExpectTrue(foe.spellPoints() < targetSpellPoints, path);
            }
            ExpectEq(1, User.countObservations(([
                "type":"combat.kata",
                "research":path,
                "qualifying opponent":1
            ])), path);
        }
    }
    destruct(foe);
}

/////////////////////////////////////////////////////////////////////////////
void ShortBladeBasicsHonorExactCooldownsAndRejectWrongGearWithoutCost()
{
    PrepareMaster();
    object foe = clone_object("/lib/realizations/npc.c");
    foe.Name("opponent");
    foe.effectiveLevel(35);
    foe.setMaxHitPoints(10000);
    move_object(foe, Room);
    foreach(string discipline in ({ "kama", "claw" }))
    {
        int kama = discipline == "kama";
        string basic = kama ? "measured-hook" : "measured-rake";
        string path = "/guilds/monk/" + discipline + "/" + basic + ".c";
        LearnPath(discipline, basic);
        RecoverAction(foe);
        EquipWeapon("implement" + discipline, kama ? "kama" : "tiger claws",
            0);
        ExpectTrue(foe.registerAttacker(User));
        ExpectTrue(User.registerAttacker(foe));
        object ability = load_object(path);
        string command = regreplace(ability.query("command template"),
            "##Target##", "opponent");
        int stamina = User.staminaPoints();
        ExpectTrue(User.executeCommand(command));
        ExpectEq(stamina - 8, User.staminaPoints());
        ExpectFalse(User.executeCommand(command));
        ExpectEq(stamina - 8, User.staminaPoints());
        User.stopFight(foe);
        foe.stopFight(User);
        for (int tick = 0; tick < (kama ? 5 : 4); tick++)
        {
            User.heart_beat();
        }
        ExpectTrue(User.blockedByCooldown(path));
        ExpectFalse(User.executeCommand(command));
        User.heart_beat();
        ExpectFalse(User.blockedByCooldown(path));
        ExpectTrue(User.executeCommand(command));
        RecoverAction(foe);
        EquipWeapon("wrong" + discipline, kama ? "short sword" : "dagger", 0);
        stamina = User.staminaPoints();
        int practice = User.countObservations(([
            "type":"combat.kata", "research":path
        ]));
        ExpectFalse(User.executeCommand(command));
        ExpectEq(stamina, User.staminaPoints());
        ExpectEq(practice, User.countObservations(([
            "type":"combat.kata", "research":path
        ])));
    }
    destruct(foe);
}

/////////////////////////////////////////////////////////////////////////////
void ShortBladeDamageUsesPrimaryWeaponAndNotAnUnrelatedOffhand()
{
    PrepareMaster();
    foreach(string discipline in ({ "kama", "claw" }))
    {
        string basic = discipline == "kama" ? "measured-hook" :
            "measured-rake";
        LearnPath(discipline, basic);
        string name = "implement" + discipline;
        object implement = EquipWeapon(name,
            discipline == "kama" ? "kama" : "tiger claws", 0);
        object ability = load_object("/guilds/monk/" + discipline +
            "/" + basic + ".c");
        int damage = ability.getEffectsToApply(User)
            ["effects"]["damage hit points"];
        ExpectTrue(implement.unequip(name));
        ExpectTrue(implement.set("weapon class", 40));
        ExpectTrue(implement.equip(name));
        int increased = ability.getEffectsToApply(User)
            ["effects"]["damage hit points"];
        ExpectTrue(increased > damage);
        object offhand = EquipWeapon("companion" + discipline, "dagger", 1);
        ExpectTrue(offhand.unequip("companion" + discipline));
        ExpectTrue(offhand.set("weapon class", 60));
        ExpectTrue(offhand.equip("companion" + discipline + " offhand"));
        ExpectEq(increased, ability.getEffectsToApply(User)
            ["effects"]["damage hit points"]);
    }
}

/////////////////////////////////////////////////////////////////////////////
void ShortBladeFormsKeepValidReplacementsAndReleaseInvalidOnes()
{
    PrepareMaster();
    User.addSkillPoints(400);
    ExpectTrue(User.advanceSkill("parry", 1));
    ExpectTrue(User.advanceSkill("dodge", 1));
    foreach(string discipline in ({ "kama", "claw" }))
    {
        int kama = discipline == "kama";
        string name = kama ? "sickle-ward" : "claw-shelter";
        string skill = kama ? "parry" : "dodge";
        string blueprint = kama ? "kama" : "tiger claws";
        string path = "/guilds/monk/" + discipline + "/" + name + ".c";
        LearnPath(discipline, name);
        RecoverAction(0);
        EquipWeapon("implement" + discipline, blueprint, 0);
        int baseline = User.getSkill(skill);
        int maximum = User.maxStaminaPoints();
        object form = load_object(path);
        string command = form.query("command template");
        ExpectTrue(User.researchCommand(command));
        ExpectEq(baseline + 3, User.getSkill(skill));
        ExpectEq(maximum - (kama ? 10 : 8), User.maxStaminaPoints());
        RecoverAction(0);
        object replacement = EquipWeapon("replacement" + discipline,
            blueprint, 0);
        ExpectTrue(User.sustainedResearchIsActive(path));
        ExpectEq(baseline + 3, User.getSkill(skill));
        EquipWeapon("wrong" + discipline, kama ? "short sword" : "dagger", 0);
        ExpectFalse(User.sustainedResearchIsActive(path));
        ExpectEq(baseline - 1, User.getSkill(skill));
        ExpectEq(maximum, User.maxStaminaPoints());
        ExpectTrue(replacement.equip("replacement" + discipline));
        ExpectFalse(User.researchCommand(command));
        User.heart_beat();
        ExpectFalse(User.researchCommand(command));
        User.heart_beat();
        ExpectTrue(User.researchCommand(command));
        ExpectTrue(User.researchCommand(command));
        ExpectEq(baseline, User.getSkill(skill));
        ExpectEq(maximum, User.maxStaminaPoints());
    }
}

/////////////////////////////////////////////////////////////////////////////
void AllEightShortBladeFormsReserveAndReleaseTheirAuthoredStamina()
{
    PrepareMaster();
    foreach(string discipline in ({ "kama", "claw" }))
    {
        int kama = discipline == "kama";
        RecoverAction(0);
        EquipWeapon("implement" + discipline, kama ? "kama" : "tiger claws",
            0);
        mapping forms = kama ? ([
            "sickle-ward":10,
            "hook-forward":12,
            "sickle-flow":14,
            "patient-sickle":18
        ]) : ([
            "claw-shelter":8,
            "forward-talon":12,
            "circling-talon":14,
            "patient-claw":18
        ]);
        foreach(string name, int reservation in forms)
        {
            LearnPath(discipline, name);
            RecoverAction(0);
            int maximum = User.maxStaminaPoints();
            object form = load_object("/guilds/monk/" + discipline +
                "/" + name + ".c");
            string command = form.query("command template");
            ExpectTrue(User.researchCommand(command), name);
            ExpectEq(maximum - reservation, User.maxStaminaPoints(), name);
            ExpectTrue(User.researchCommand(command), name);
            ExpectEq(maximum, User.maxStaminaPoints(), name);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void ShortBladeRecenteringHealsWithoutWeaponScaling()
{
    PrepareMaster();
    object foe = clone_object("/lib/realizations/npc.c");
    foe.Name("opponent");
    foe.effectiveLevel(35);
    move_object(foe, Room);
    foreach(string discipline in ({ "kama", "claw" }))
    {
        string name = discipline == "kama" ? "sickle-recentering" :
            "claw-recentering";
        LearnPath(discipline, name);
        RecoverAction(foe);
        EquipWeapon("implement" + discipline,
            discipline == "kama" ? "kama" : "tiger claws", 0);
        User.hitPoints(10000);
        ExpectTrue(User.hit(40, "physical", foe) > 0);
        int health = User.hitPoints();
        int stamina = User.staminaPoints();
        int spellPoints = User.spellPoints();
        object ability = load_object("/guilds/monk/" + discipline +
            "/" + name + ".c");
        foreach(mapping modifier in ability.query("modifiers"))
        {
            ExpectFalse(modifier["type"] == "weapon damage");
            ExpectFalse(modifier["type"] == "offhand damage");
        }
        ExpectTrue(User.executeCommand(ability.query("command template")));
        ExpectTrue(User.hitPoints() > health);
        ExpectEq(stamina - 6, User.staminaPoints());
        ExpectEq(spellPoints - 8, User.spellPoints());
    }
    destruct(foe);
}

/////////////////////////////////////////////////////////////////////////////
void CommittedCutUsesItsHeavyCostAndExactEighteenSecondCooldown()
{
    PrepareMaster();
    LearnPath("odachi", "committed-cut");
    EquipWeapon("odachi", "odachi", 0);
    object target = clone_object("/lib/realizations/npc.c");
    target.Name("opponent");
    target.effectiveLevel(16);
    target.setMaxHitPoints(10000);
    move_object(target, Room);
    RecoverAction(target);
    int stamina = User.staminaPoints();
    int health = target.hitPoints();
    ExpectTrue(User.researchCommand("kata committed cut at opponent"));
    ExpectEq(stamina - 14, User.staminaPoints());
    ExpectTrue(target.hitPoints() < health);
    User.stopFight(target);
    target.stopFight(User);
    for (int tick = 0; tick < 8; tick++)
    {
        User.heart_beat();
    }
    health = target.hitPoints();
    stamina = User.staminaPoints();
    ExpectFalse(User.researchCommand("kata committed cut at opponent"));
    ExpectEq(health, target.hitPoints());
    ExpectEq(stamina, User.staminaPoints());
    User.heart_beat();
    stamina = User.staminaPoints();
    ExpectTrue(User.researchCommand("kata committed cut at opponent"));
    ExpectEq(stamina - 14, User.staminaPoints());
    ExpectEq(2, User.countObservations(([
        "type":"combat.kata",
        "research":"/guilds/monk/odachi/committed-cut.c"
    ])));
    RecoverAction(target);
    EquipWeapon("claymore", "claymore", 0);
    stamina = User.staminaPoints();
    ExpectFalse(User.researchCommand("kata committed cut at opponent"));
    ExpectEq(stamina, User.staminaPoints());
    ExpectEq(2, User.countObservations(([
        "type":"combat.kata",
        "research":"/guilds/monk/odachi/committed-cut.c"
    ])));
    destruct(target);
}
