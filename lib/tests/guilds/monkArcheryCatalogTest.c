//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/support/guilds/monkTrialFixture.c";

object User;
object Lian;
object Ren;
object Iori;
object Room;
object Target;
object Arrows;
object *Weapons;
int StudentNumber;
string Base = "/guilds/monk/archery/";
string Draw = "/guilds/monk/archery/measured-draw.c";

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    load_object("/guilds/monk/monk.c");
    ignoreList += ({ "AdvanceTo", "PrepareDisciple", "PrepareMaster",
        "LearnPath", "EquipWeapon", "RecoverAction", "LearnDraw",
        "TeachMonkTrialLesson", "CompleteMonkUpperTrial" });
    Room = clone_object("/lib/environment/environment.c");
    Lian = clone_object("/guilds/monk/teachers/lian.c");
    Ren = clone_object("/guilds/monk/teachers/ren.c");
    Iori = clone_object("/guilds/monk/teachers/iori.c");
    foreach(object teacher in ({ Lian, Ren, Iori }))
    {
        move_object(teacher, Room);
    }
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Weapons = ({});
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name(sprintf("archer%d", ++StudentNumber));
    User.Str(20);
    User.Int(20);
    User.Dex(20);
    User.Con(20);
    User.Wis(20);
    User.Chr(20);
    User.colorConfiguration("none");
    Target = clone_object("/lib/realizations/npc.c");
    Target.Name("opponent");
    Target.effectiveLevel(35);
    Target.setMaxHitPoints(10000);
    Arrows = clone_object("/lib/items/ammunition.c");
    Arrows.set("name", "practice quiver");
    Arrows.set("ammunition type", "arrow");
    Arrows.set("max capacity", 40);
    Arrows.set("quantity", 40);
    move_object(User, Room);
    move_object(Target, Room);
    move_object(Arrows, User);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    foreach(object weapon in Weapons)
    {
        if (objectp(weapon))
        {
            destruct(weapon);
        }
    }
    destruct(Arrows);
    destruct(Target);
    destruct(User);
}

/////////////////////////////////////////////////////////////////////////////
void TearDown()
{
    destruct(Iori);
    destruct(Ren);
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
void PrepareDisciple(int recognized)
{
    ExpectTrue(User.joinGuild("monk"));
    User.addResearchPoints(500);
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/initiates-discipline.c"));
    AdvanceTo(10);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(User.advanceRank("monk"));
    if (recognized)
    {
        ExpectTrue(User.learnResearchFrom(Lian,
            "/guilds/monk/discipline/steady-practice.c"));
        ExpectTrue(User.learnResearchFrom(Lian,
            "/guilds/monk/discipline/teachers-recognition.c"));
    }
    AdvanceTo(19);
    ExpectTrue(User.isResearched(Base + "root.c"));
    AdvanceTo(20);
    ExpectTrue(User.isResearched(Base + "root.c"));
    ExpectTrue(member(User.availableResearchTrees(),
        "/guilds/monk/archery.c") >= 0);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/students-awareness.c"));
    ExpectTrue(User.advanceRank("monk"));
}

/////////////////////////////////////////////////////////////////////////////
void PrepareMaster()
{
    PrepareDisciple(1);
    string *foundations = ({ "disciples-insight", "adepts-focus",
        "inner-discipline", "mastery-of-fundamentals" });
    for (int index = 0; index < sizeof(foundations); index++)
    {
        AdvanceTo(MonkPromotionLevels[index + 2]);
        ExpectTrue(User.initiateResearch("/guilds/monk/discipline/" +
            foundations[index] + ".c"));
        if (!index)
        {
            for (int use = 0; use < 10; use++)
            {
                User.recordObservation(([
                    "type":"combat.kata",
                    "context":([
                        "research":"/guilds/monk/unarmed/measured-palm.c",
                        "qualifying opponent":1
                    ])
                ]), 1);
            }
            ExpectTrue(User.learnResearchFrom(Ren,
                "/guilds/monk/discipline/adepts-trial.c"));
        }
        if (index)
        {
            CompleteMonkUpperTrial(User, Lian, Ren, index - 1);
        }
        ExpectTrue(User.advanceRank("monk"));
    }
    ExpectEq("master", User.guildRank("monk"));
}

/////////////////////////////////////////////////////////////////////////////
void LearnPath(string name)
{
    string path = Base + name + ".c";
    TeachMonkTrialLesson(User, ({ Iori }), path);
}

/////////////////////////////////////////////////////////////////////////////
object EquipWeapon(string blueprint)
{
    object weapon = clone_object("/lib/items/weapon.c");
    weapon.set("blueprint", blueprint);
    weapon.set("name", blueprint);
    move_object(weapon, User);
    Weapons += ({ weapon });
    ExpectTrue(weapon.equip(blueprint), "Equipping " + blueprint);
    return weapon;
}

/////////////////////////////////////////////////////////////////////////////
void RecoverAction()
{
    User.stopFight(Target);
    Target.stopFight(User);
    for (int tick = 0; tick < 16; tick++)
    {
        User.heart_beat();
    }
    User.hitPoints(10000);
    User.staminaPoints(10000);
    User.spellPoints(10000);
    Target.hitPoints(10000);
    Target.staminaPoints(10000);
    Target.spellPoints(10000);
    ExpectTrue(Target.registerAttacker(User));
    ExpectTrue(User.registerAttacker(Target));
}

/////////////////////////////////////////////////////////////////////////////
void LearnDraw()
{
    PrepareDisciple(1);
    LearnPath("measured-draw");
    EquipWeapon("long bow");
    RecoverAction();
}

/////////////////////////////////////////////////////////////////////////////
void FortyLessonsHaveMixedTypesAndExecutableKnowledgeReceivers()
{
    object tree = getService("research")->researchTree(
        "/guilds/monk/archery.c");
    mapping items = tree->getFlattenedResearchTree();
    mapping counts = ([]);
    mapping names = ([]);
    ExpectEq(41, sizeof(items));
    foreach(object item in m_indices(items))
    {
        names[item->query("name")] = item;
        if (item->query("research type") != "tree root")
        {
            counts[item->query("type")]++;
            ExpectTrue(item->isValidResearchItem());
            ExpectTrue(item->query("teacher required"));
            ExpectTrue(sizeof(tree->getParents(program_name(item))) > 0);
            ExpectTrue(Iori.teachesResearch(program_name(item)));
            ExpectFalse(Ren.teachesResearch(program_name(item)));
            ExpectFalse(Lian.teachesResearch(program_name(item)));
            ExpectFalse(item->checkPrerequisites(User));
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
                int wired = 0;
                if (receiver)
                {
                    string path = program_name(item);
                    mixed modifiers = receiver->query("modifiers");
                    if (pointerp(modifiers))
                    {
                        foreach(mapping modifier in modifiers)
                        {
                            wired ||= modifier["type"] == "research" &&
                                modifier["research item"] == path &&
                                modifier["formula"] == "additive" &&
                                modifier["base value"] == 1 &&
                                modifier["rate"] ==
                                    to_float(affected[name]);
                        }
                    }
                    foreach(string key in ({
                        "stamina point cost modifiers",
                        "cooldown modifiers" }))
                    {
                        mixed reductions = receiver->query(key);
                        wired ||= mappingp(reductions) &&
                            reductions[path] == affected[name];
                    }
                }
                ExpectTrue(wired, program_name(item));
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void AllFortyLessonsAreGenuinelyReachableThroughIori()
{
    PrepareMaster();
    object tree = getService("research")->researchTree(
        "/guilds/monk/archery.c");
    int count = 0;
    foreach(object item in m_indices(tree->getFlattenedResearchTree()))
    {
        if (item->query("research type") != "tree root")
        {
            string path = program_name(item);
            LearnPath(regreplace(path, "^.*/([^/]+).c$", "\\1"));
            ExpectTrue(User.isResearched(path), path);
            count++;
        }
    }
    ExpectEq(40, count);
}

/////////////////////////////////////////////////////////////////////////////
void RecognitionAndNearbyCorrectTeacherAreRequiredForAdvancedLessons()
{
    PrepareDisciple(0);
    ExpectTrue(User.learnResearchFrom(Iori, Draw));
    ExpectTrue(User.learnResearchFrom(Iori, Base + "archers-grip.c"));
    string lesson = Base + "archers-footing.c";
    int points = User.researchPoints();
    ExpectFalse(User.learnResearchFrom(Iori, lesson));
    ExpectEq(points, User.researchPoints());
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/steady-practice.c"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/teachers-recognition.c"));
    ExpectFalse(User.initiateResearch(lesson));
    ExpectFalse(User.learnResearchFrom(Ren, lesson));
    move_object(Iori, this_object());
    ExpectFalse(User.learnResearchFrom(Iori, lesson));
    move_object(Iori, Room);
    ExpectTrue(User.executeCommand("lessons from iori"));
    ExpectSubStringMatch("Measured Draw", User.caughtMessage());
    ExpectTrue(User.executeCommand("learn archer's footing from iori"));
    points = User.researchPoints();
    int respect = Iori.relationshipValue(User, "respect");
    ExpectFalse(User.learnResearchFrom(Iori, lesson));
    ExpectEq(points, User.researchPoints());
    ExpectEq(respect, Iori.relationshipValue(User, "respect"));
    ExpectTrue(User.leaveGuild("monk"));
    ExpectFalse(User.learnResearchFrom(Iori, Base + "archers-guard.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AllFiveBowBlueprintsQualifyButCarriedAndOtherWeaponsDoNot()
{
    PrepareDisciple(1);
    LearnPath("measured-draw");
    LearnPath("archers-grip");
    object draw = load_object(Draw);
    int bonus = User.researchBonusTo("bow");
    ExpectFalse(draw.canApplySpecification("", User));
    foreach(string blueprint in ({ "short bow", "bow", "long bow",
        "recurve bow", "composite bow" }))
    {
        object bow = EquipWeapon(blueprint);
        ExpectTrue(draw.canApplySpecification("", User), blueprint);
        ExpectEq(bow, User.equipmentInSlot("wielded primary"));
        ExpectEq(bonus + 1, User.researchBonusTo("bow"));
        ExpectTrue(bow.unequip(blueprint));
        ExpectFalse(draw.canApplySpecification("", User));
    }
    foreach(string blueprint in ({ "crossbow", "sling", "katana" }))
    {
        EquipWeapon(blueprint);
        ExpectFalse(draw.canApplySpecification("", User), blueprint);
        ExpectEq(bonus, User.researchBonusTo("bow"));
    }
}

/////////////////////////////////////////////////////////////////////////////
void KnowledgeChangesRealDamageCostsAndCooldowns()
{
    PrepareMaster();
    LearnPath("measured-draw");
    EquipWeapon("long bow");
    object draw = load_object(Draw);
    int damage = draw.getEffectsToApply(User)["effects"]["damage hit points"];
    LearnPath("draw-geometry");
    ExpectEq(damage + 3,
        draw.getEffectsToApply(User)["effects"]["damage hit points"]);
    ExpectEq(10, draw.getUsageCosts("", User)["stamina point cost"]);
    LearnPath("draw-economy");
    ExpectEq(8, draw.getUsageCosts("", User)["stamina point cost"]);
    LearnPath("crosswind-shot");
    object crosswind = load_object(Base + "crosswind-shot.c");
    ExpectEq(18, crosswind.cooldown(User));
    LearnPath("crosswind-rhythm");
    ExpectEq(14, crosswind.cooldown(User));
    LearnPath("final-draw");
    object finalDraw = load_object(Base + "final-draw.c");
    ExpectEq(24, finalDraw.getUsageCosts("", User)["stamina point cost"]);
    LearnPath("final-draw-economy");
    ExpectEq(21, finalDraw.getUsageCosts("", User)["stamina point cost"]);
}

/////////////////////////////////////////////////////////////////////////////
void BowWeaponDamageContributesToActualShotFormula()
{
    PrepareDisciple(1);
    LearnPath("measured-draw");
    object bow = EquipWeapon("long bow");
    object draw = load_object(Draw);
    int damage = draw.getEffectsToApply(User)["effects"]["damage hit points"];
    ExpectTrue(bow.unequip("long bow"));
    ExpectTrue(bow.set("weapon class", 40));
    ExpectTrue(bow.equip("long bow"));
    ExpectTrue(draw.getEffectsToApply(User)["effects"]["damage hit points"] >
        damage);
}

/////////////////////////////////////////////////////////////////////////////
void MeasuredDrawConsumesOneArrowTenStaminaAndRecordsOneUse()
{
    LearnDraw();
    int health = Target.hitPoints();
    int stamina = User.staminaPoints();
    ExpectTrue(User.executeCommand("kata measured draw at opponent"));
    ExpectTrue(Target.hitPoints() < health);
    ExpectEq(stamina - 10, User.staminaPoints());
    ExpectEq(39, Arrows.query("quantity"));
    ExpectEq(1, User.countObservations(([
        "type":"combat.kata", "research":Draw, "qualifying opponent":1
    ])));
    ExpectTrue(User.blockedByCooldown(Draw));
    ExpectFalse(User.executeCommand("kata measured draw at opponent"));
    ExpectEq(stamina - 10, User.staminaPoints());
    ExpectEq(39, Arrows.query("quantity"));
    User.stopFight(Target);
    Target.stopFight(User);
    for (int tick = 0; tick < 6; tick++)
    {
        User.heart_beat();
    }
    ExpectTrue(User.blockedByCooldown(Draw));
    ExpectFalse(User.executeCommand("kata measured draw at opponent"));
    ExpectEq(39, Arrows.query("quantity"));
    User.heart_beat();
    ExpectFalse(User.blockedByCooldown(Draw));
    ExpectTrue(User.executeCommand("kata measured draw at opponent"));
    ExpectEq(38, Arrows.query("quantity"));
}

/////////////////////////////////////////////////////////////////////////////
void MissingArrowsFailClearlyWithoutCostsCooldownOrPractice()
{
    LearnDraw();
    Arrows.set("quantity", 0);
    int health = Target.hitPoints();
    int stamina = User.staminaPoints();
    ExpectFalse(User.executeCommand("kata measured draw at opponent"));
    ExpectSubStringMatch("required arrow", User.caughtMessage());
    ExpectEq(health, Target.hitPoints());
    ExpectEq(stamina, User.staminaPoints());
    ExpectFalse(User.blockedByCooldown(Draw));
    ExpectEq(0, User.countObservations(([
        "type":"combat.kata", "research":Draw
    ])));
    ExpectTrue(objectp(Arrows));
    RecoverAction();
    Arrows.set("quantity", 1);
    ExpectTrue(User.executeCommand("kata measured draw at opponent"));
    ExpectEq(0, Arrows.query("quantity"));
    ExpectTrue(objectp(Arrows));
}

/////////////////////////////////////////////////////////////////////////////
void WrongAmmunitionAndRemoteArrowsDoNotQualify()
{
    LearnDraw();
    Arrows.set("ammunition type", "bolt");
    ExpectFalse(User.executeCommand("kata measured draw at opponent"));
    ExpectEq(40, Arrows.query("quantity"));
    RecoverAction();
    Arrows.set("ammunition type", "arrow");
    move_object(Arrows, this_object());
    ExpectFalse(User.executeCommand("kata measured draw at opponent"));
    ExpectEq(40, Arrows.query("quantity"));
    RecoverAction();
    move_object(Arrows, Room);
    ExpectTrue(User.executeCommand("kata measured draw at opponent"));
    ExpectEq(39, Arrows.query("quantity"));
}

/////////////////////////////////////////////////////////////////////////////
void WrongGearMissingTargetsAndInsufficientStaminaWasteNothing()
{
    LearnDraw();
    EquipWeapon("crossbow");
    int stamina = User.staminaPoints();
    ExpectFalse(User.executeCommand("kata measured draw at opponent"));
    ExpectEq(stamina, User.staminaPoints());
    ExpectEq(40, Arrows.query("quantity"));
    EquipWeapon("long bow");
    RecoverAction();
    ExpectFalse(User.executeCommand("kata measured draw at absent"));
    ExpectEq(40, Arrows.query("quantity"));
    ExpectFalse(User.blockedByCooldown(Draw));
    User.staminaPoints(-User.staminaPoints());
    ExpectFalse(User.executeCommand("kata measured draw at opponent"));
    ExpectEq(40, Arrows.query("quantity"));
    ExpectEq(0, User.countObservations(([
        "type":"combat.kata", "research":Draw
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void AllElevenShotsConsumeArrowsAndApplyTheirAuthoredResourceEffect()
{
    PrepareMaster();
    EquipWeapon("long bow");
    foreach(string name in ({ "measured-draw", "arresting-shot",
        "crosswind-shot", "breath-piercing-shot", "burdening-shot",
        "descending-shot", "narrow-line-shot", "returning-shot",
        "exhausting-shot", "final-draw", "quieting-shot" }))
    {
        LearnPath(name);
        RecoverAction();
        object shot = load_object(Base + name + ".c");
        ExpectEq("arrow", shot.query("damage type"));
        ExpectEq(([ "arrow":1 ]), shot.query("consumables"));
        int arrows = Arrows.query("quantity");
        int health = Target.hitPoints();
        int stamina = Target.staminaPoints();
        int spellPoints = Target.spellPoints();
        string command = regreplace(shot.query("command template"),
            "##Target##", "opponent");
        ExpectTrue(User.executeCommand(command), name);
        ExpectEq(arrows - 1, Arrows.query("quantity"), name);
        if (shot.query("damage hit points"))
        {
            ExpectTrue(Target.hitPoints() < health, name);
        }
        else if (shot.query("damage stamina points"))
        {
            ExpectTrue(Target.staminaPoints() < stamina, name);
        }
        else
        {
            ExpectTrue(Target.spellPoints() < spellPoints, name);
        }
        ExpectEq(1, User.countObservations(([
            "type":"combat.kata", "research":Base + name + ".c",
            "qualifying opponent":1
        ])), name);
    }
}

/////////////////////////////////////////////////////////////////////////////
void PatientDrawRetainsBonusesAcrossBowsAndCancelsOnInvalidEquipment()
{
    PrepareMaster();
    LearnPath("patient-draw");
    object bow = EquipWeapon("long bow");
    User.addSkillPoints(200);
    ExpectTrue(User.advanceSkill("bow", 1));
    int skill = User.getSkill("bow");
    int maximum = User.maxStaminaPoints();
    int arrows = Arrows.query("quantity");
    ExpectTrue(User.executeCommand("kata patient draw"));
    ExpectEq(skill + 3, User.getSkill("bow"));
    ExpectEq(maximum - 10, User.maxStaminaPoints());
    RecoverAction();
    bow = EquipWeapon("recurve bow");
    ExpectTrue(User.sustainedResearchIsActive(Base + "patient-draw.c"));
    ExpectEq(skill + 3, User.getSkill("bow"));
    ExpectEq(maximum - 10, User.maxStaminaPoints());
    ExpectEq(arrows, Arrows.query("quantity"));
    EquipWeapon("crossbow");
    ExpectFalse(User.sustainedResearchIsActive(Base + "patient-draw.c"));
    ExpectEq(skill - 1, User.getSkill("bow"));
    ExpectEq(maximum, User.maxStaminaPoints());
    ExpectTrue(bow.equip("recurve bow"));
    ExpectFalse(User.executeCommand("kata patient draw"));
    User.heart_beat();
    ExpectFalse(User.executeCommand("kata patient draw"));
    User.heart_beat();
    ExpectTrue(User.executeCommand("kata patient draw"));
    ExpectTrue(User.executeCommand("kata patient draw"));
    ExpectEq(skill, User.getSkill("bow"));
    ExpectEq(maximum, User.maxStaminaPoints());
}

/////////////////////////////////////////////////////////////////////////////
void EveryFormReservesStaminaAndCanBeReleasedWithoutArrows()
{
    PrepareMaster();
    EquipWeapon("long bow");
    Arrows.set("quantity", 0);
    foreach(string name, int reservation in ([
        "patient-draw":10, "forward-draw":14,
        "mobile-draw":16, "still-bow":20
    ]))
    {
        LearnPath(name);
        RecoverAction();
        int maximum = User.maxStaminaPoints();
        object form = load_object(Base + name + ".c");
        string command = form.query("command template");
        ExpectTrue(User.executeCommand(command), name);
        ExpectEq(maximum - reservation, User.maxStaminaPoints());
        ExpectTrue(User.executeCommand(command), name);
        ExpectEq(maximum, User.maxStaminaPoints());
        ExpectEq(0, Arrows.query("quantity"));
    }
}

/////////////////////////////////////////////////////////////////////////////
void RecenteringHealsWithResourceCostsButNoArrowOrWeaponDamage()
{
    PrepareMaster();
    LearnPath("archers-recentering");
    EquipWeapon("long bow");
    RecoverAction();
    Arrows.set("quantity", 0);
    ExpectTrue(User.hit(40, "physical", Target) > 0);
    int health = User.hitPoints();
    int stamina = User.staminaPoints();
    int spellPoints = User.spellPoints();
    object heal = load_object(Base + "archers-recentering.c");
    foreach(mapping modifier in heal.query("modifiers"))
    {
        ExpectFalse(modifier["type"] == "weapon damage");
    }
    ExpectTrue(User.executeCommand("kata archer's recentering"),
        "Executing recentering");
    ExpectTrue(User.hitPoints() > health,
        sprintf("Healing from %d: %s", health, User.caughtMessage()));
    ExpectEq(stamina - 6, User.staminaPoints());
    ExpectEq(spellPoints - 8, User.spellPoints());
    ExpectEq(0, Arrows.query("quantity"));
}
