//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/support/guilds/monkTrialFixture.c";

object Tree;
object User;
object Room;
object Weapon;
object Offhand;
string Base = "/guilds/monk/bludgeon/";

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    load_object("/guilds/monk/monk.c");
    ignoreList += ({ "AdvanceMonk", "EquipBlueprint", "PrepareMaster",
        "LearnPath", "TeachMonkTrialLesson", "CompleteMonkUpperTrial" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Tree = load_object("/guilds/monk/bludgeon.c");
    Room = clone_object("/lib/environment/environment.c");
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("catalog tester");
    User.Race("human");
    User.Str(20);
    User.Int(20);
    User.Dex(20);
    User.Con(20);
    User.Wis(20);
    User.Chr(20);
    User.colorConfiguration("none");
    move_object(User, Room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (Offhand)
    {
        destruct(Offhand);
    }
    if (Weapon)
    {
        destruct(Weapon);
    }
    destruct(User);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void EquipBlueprint(string blueprint)
{
    if (Weapon)
    {
        destruct(Weapon);
    }
    Weapon = clone_object("/lib/items/weapon.c");
    Weapon.set("blueprint", blueprint);
    Weapon.set("name", "implement");
    move_object(Weapon, User);
    ExpectTrue(Weapon.equip("implement"));
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceMonk(int level)
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
void PrepareMaster(object lian, object ren)
{
    ExpectTrue(User.joinGuild("monk"));
    User.addResearchPoints(500);
    ExpectTrue(User.learnResearchFrom(lian,
        "/guilds/monk/discipline/initiates-discipline.c"));
    string *foundations = ({ "disciplined-breath", "students-awareness",
        "disciples-insight", "adepts-focus", "inner-discipline",
        "mastery-of-fundamentals" });
    for (int index = 0; index < sizeof(foundations); index++)
    {
        AdvanceMonk(MonkPromotionLevels[index]);
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
            ExpectTrue(User.learnResearchFrom(ren,
                "/guilds/monk/discipline/adepts-trial.c"));
        }
        if (index >= 3)
        {
            CompleteMonkUpperTrial(User, lian, ren, index - 3);
        }
        ExpectTrue(User.advanceRank("monk"));
        if (index == 0)
        {
            ExpectTrue(User.learnResearchFrom(lian,
                "/guilds/monk/discipline/steady-practice.c"));
            ExpectTrue(User.learnResearchFrom(lian,
                "/guilds/monk/discipline/teachers-recognition.c"));
        }
    }
    ExpectEq("master", User.guildRank("monk"));
}

/////////////////////////////////////////////////////////////////////////////
void LearnPath(string path, object ren)
{
    if (!User.isResearched(path))
    {
        foreach (string parent in Tree.getParents(path))
        {
            LearnPath(parent, ren);
        }
        object item = load_object(path);
        foreach (string prerequisite, mapping details in
            item.getPrerequisites())
        {
            if (details["type"] == "research" &&
                prerequisite[0..sizeof(Base) - 1] == Base)
            {
                LearnPath(prerequisite, ren);
            }
        }
        ExpectTrue(ren.teachesResearch(path), path);
        ExpectTrue(User.canResearch(path), path);
        ExpectTrue(User.learnResearchFrom(ren, path), path);
        ExpectTrue(User.isResearched(path), path);
    }
}

/////////////////////////////////////////////////////////////////////////////
void EveryBludgeonItemIsLearnableThroughRealTeachersAndDependencies()
{
    object lian = clone_object("/guilds/monk/teachers/lian.c");
    object ren = clone_object("/guilds/monk/teachers/ren.c");
    move_object(lian, Room);
    move_object(ren, Room);
    PrepareMaster(lian, ren);
    int learned = 0;
    foreach (object item in m_indices(Tree.getFlattenedResearchTree()))
    {
        if (item.query("research type") != "tree root")
        {
            string path = program_name(item);
            LearnPath(path, ren);
            ExpectTrue(User.isResearched(path), path);
            learned++;
        }
    }
    ExpectEq(40, learned);
    destruct(ren);
    destruct(lian);
}

/////////////////////////////////////////////////////////////////////////////
void FortyNonRootItemsHaveRealAndVariedEffects()
{
    mapping catalog = Tree.getFlattenedResearchTree();
    mapping counts = ([
        "knowledge":0,
        "passive":0,
        "active":0,
        "sustained":0
    ]);
    ExpectEq(41, sizeof(catalog));
    foreach (object item in m_indices(catalog))
    {
        if (item.query("research type") != "tree root")
        {
            string type = item.query("type");
            counts[type]++;
            ExpectEq("monk", item.query("source"));
            ExpectEq("points", item.query("research type"));
            ExpectEq(1, item.query("teacher required"));
            ExpectTrue(item.query("research cost") >= 2);
            ExpectTrue(item.query("research cost") <= 4);
            ExpectTrue(sizeof(Tree.getParents(program_name(item))) > 0);
            if (type == "knowledge")
            {
                ExpectTrue(sizeof(item.query("affected research")) > 0);
            }
            else if (type == "passive" || type == "sustained")
            {
                ExpectTrue(sizeof(item.query("bonuses")) > 0);
            }
            else
            {
                ExpectTrue(pointerp(item.query("damage hit points")) ||
                    pointerp(item.query("damage stamina points")));
                ExpectTrue(sizeof(item.query("modifiers")) > 0);
                ExpectTrue(item.query("stamina point cost") >= 6);
                ExpectTrue(item.query("cooldown") >= 8);
            }
        }
    }
    ExpectEq(13, counts["knowledge"]);
    ExpectEq(11, counts["passive"]);
    ExpectEq(11, counts["active"]);
    ExpectEq(5, counts["sustained"]);
}

/////////////////////////////////////////////////////////////////////////////
void NewItemsRequireMembershipRankLevelAndExplicitResearchParents()
{
    int checked = 0;
    foreach (object item in m_indices(Tree.getFlattenedResearchTree()))
    {
        string path = program_name(item);
        if (item.query("research type") != "tree root" &&
            path != Base + "measured-impact.c" &&
            path != Base + "settled-guard.c")
        {
            mapping prerequisites = item.getPrerequisites();
            int level = prerequisites["level"]["value"];
            ExpectEq("guild", prerequisites["monk"]["type"]);
            ExpectEq(({ "monk" }), prerequisites["monk"]["value"]);
            ExpectEq("monk", prerequisites["level"]["guild"]);
            ExpectEq("guild rank", prerequisites["rank"]["type"]);
            ExpectEq(level < 10 ? "initiate" :
                level < 20 ? "student" : level < 30 ? "disciple" :
                level < 40 ? "adept" : level < 55 ? "senior disciple" :
                level < 70 ? "master candidate" : "master",
                prerequisites["rank"]["value"][0]);
            foreach (string parent in Tree.getParents(path))
            {
                ExpectEq("research", prerequisites[parent]["type"]);
            }
            ExpectFalse(item.checkPrerequisites(User));
            ExpectFalse(User.initiateResearch(path));
            checked++;
        }
    }
    ExpectEq(38, checked);
}

/////////////////////////////////////////////////////////////////////////////
void EveryKnowledgeEffectHasAnExecutableReceiver()
{
    mapping byName = ([]);
    foreach (object item in m_indices(Tree.getFlattenedResearchTree()))
    {
        byName[item.query("name")] = item;
    }
    foreach (object knowledge in m_values(byName))
    {
        if (knowledge.query("type") == "knowledge" &&
            knowledge.query("research type") != "tree root")
        {
            foreach (string name, int amount in
                knowledge.query("affected research"))
            {
                object receiver = byName[name];
                string path = program_name(knowledge);
                string type = knowledge.query("affected research type");
                ExpectTrue(objectp(receiver));
                if (type == "decrease cooldown")
                {
                    ExpectEq(amount,
                        receiver.query("cooldown modifiers")[path]);
                }
                else if (type == "decrease cost")
                {
                    ExpectEq(amount,
                        receiver.query("stamina point cost modifiers")[path]);
                }
                else
                {
                    mapping *modifiers = filter(receiver.query("modifiers"),
                        (: $1["type"] == "research" &&
                            $1["research item"] == $2 :), path);
                    ExpectEq(1, sizeof(modifiers));
                    ExpectEq(1, modifiers[0]["base value"]);
                    ExpectEq(type == "percentage" ?
                        "multiplicative" : "additive",
                        modifiers[0]["formula"]);
                    ExpectEq(type == "percentage" ?
                        1.0 + amount / 100.0 : to_float(amount),
                        modifiers[0]["rate"]);
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void RuntimeEquipmentLimitsCoverKnowledgePassivesSustainsAndAttacks()
{
    foreach (string blueprint in ({ "staff", "quarterstaff", "mace",
        "flanged mace", "morning star", "war hammer", "club", "katana" }))
    {
        EquipBlueprint(blueprint);
        foreach (object item in m_indices(Tree.getFlattenedResearchTree()))
        {
            if (item.query("research type") != "tree root")
            {
                mapping equipment = item.query("limited by")["equipment"];
                mixed types = equipment["type"];
                mixed blueprints = equipment["blueprint"];
                string weaponType = Weapon.query("weapon type");
                int expected = pointerp(types) ?
                    member(types, weaponType) >= 0 : types == weaponType;
                if (blueprints)
                {
                    expected &&= pointerp(blueprints) ?
                        member(blueprints, blueprint) >= 0 :
                        blueprints == blueprint;
                }
                ExpectEq("wielded primary", equipment["slot"]);
                ExpectEq(expected, item.canApplySpecification(
                    "bonus attack", User));
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void FamilyBonusesRequireBothLiveTypeAndBlueprint()
{
    EquipBlueprint("mace");
    object grip = load_object(Base + "close-haft-grip.c");
    object broad = load_object(Base + "grounded-footwork.c");
    object staffGrip = load_object(Base + "balanced-grip.c");
    ExpectTrue(grip.canApplySpecification("bonus mace", User));
    Offhand = clone_object("/lib/items/weapon.c");
    Offhand.set("blueprint", "dagger");
    Offhand.set("name", "dagger");
    move_object(Offhand, User);
    ExpectTrue(Offhand.equip("dagger offhand"));
    ExpectTrue(grip.canApplySpecification("bonus mace", User));
    Weapon.set("weapon type", "staff");
    ExpectFalse(grip.canApplySpecification("bonus mace", User));
    ExpectTrue(broad.canApplySpecification("bonus defense", User));
    ExpectFalse(staffGrip.canApplySpecification("bonus staff", User));
    Weapon.set("weapon type", "long sword");
    ExpectFalse(broad.canApplySpecification("bonus defense", User));
    Weapon.set("weapon type", "mace");
    ExpectTrue(Weapon.unequip("implement"));
    ExpectFalse(grip.canApplySpecification("bonus mace", User));
}

/////////////////////////////////////////////////////////////////////////////
void MasteryPassivesRequireBothDefensiveAndKnowledgeBranches()
{
    foreach (string item, string *parents in ([
        "staff-equilibrium":({ "crossbar-defense", "long-reach-geometry" }),
        "mace-composure":({ "haft-shelter", "contact-geometry" }),
        "hammer-poise":({ "braced-recovery", "anvil-geometry" })
    ]))
    {
        mapping prerequisites =
            load_object(Base + item + ".c").getPrerequisites();
        ExpectEq(item == "staff-equilibrium" ? 56 :
            item == "mace-composure" ? 58 : 60,
            prerequisites["level"]["value"]);
        string *ranks = prerequisites["rank"]["value"];
        ExpectEq(2, sizeof(ranks));
        ExpectTrue(member(ranks, "master candidate") >= 0);
        ExpectTrue(member(ranks, "master") >= 0);
        foreach (string parent in parents)
        {
            ExpectEq("research",
                prerequisites[Base + parent + ".c"]["type"]);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void FoundationKnowledgeActuallyChangesMeasuredImpactCooldown()
{
    object lian = clone_object("/guilds/monk/teachers/lian.c");
    object ren = clone_object("/guilds/monk/teachers/ren.c");
    object impact = load_object(Base + "measured-impact.c");
    move_object(lian, Room);
    move_object(ren, Room);
    ExpectTrue(User.joinGuild("monk"));
    ExpectTrue(User.learnResearchFrom(lian,
        "/guilds/monk/discipline/initiates-discipline.c"));
    AdvanceMonk(10);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(User.advanceRank("monk"));
    ExpectTrue(User.learnResearchFrom(lian,
        "/guilds/monk/discipline/steady-practice.c"));
    ExpectTrue(User.learnResearchFrom(lian,
        "/guilds/monk/discipline/teachers-recognition.c"));
    AdvanceMonk(20);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/students-awareness.c"));
    ExpectTrue(User.advanceRank("monk"));
    ExpectEq(8, impact.cooldown(User));
    ExpectFalse(User.canResearch(Base + "impact-theory.c"));
    ExpectTrue(User.learnResearchFrom(ren, Base + "measured-impact.c"));
    ExpectTrue(User.learnResearchFrom(ren, Base + "settled-guard.c"));
    ExpectTrue(User.canResearch(Base + "impact-theory.c"));
    ExpectFalse(User.initiateResearch(Base + "impact-theory.c"));
    ExpectTrue(User.learnResearchFrom(ren, Base + "impact-theory.c"));
    ExpectEq(7, impact.cooldown(User));
    ExpectEq(6, impact.query("stamina point cost"));
    ExpectEq(1, load_object(Base + "settled-guard.c").query("bonus parry"));
    ExpectTrue(User.canResearch(Base + "staff-fulcrum.c"));
    ExpectTrue(User.canResearch(Base + "mace-head-alignment.c"));
    ExpectTrue(User.canResearch(Base + "hammer-counterweight.c"));
    destruct(ren);
    destruct(lian);
}
