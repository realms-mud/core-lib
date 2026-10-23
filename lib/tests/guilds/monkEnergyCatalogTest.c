//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/tests/support/guilds/monk-trials.h"

object User;
object Room;
object Lian;
object Ren;
int EnergyLessonsLearned;
string Chi = "/guilds/monk/pure-chi/";
string Shield = "/guilds/monk/mana-shield/";

void Init()
{
    load_object("/guilds/monk/monk.c");
    ignoreList += ({ "CheckCatalog", "PrepareDisciple", "AdvanceMonk",
        "PrepareMaster", "TeachEnergyLesson", "TeachMonkTrialLesson",
        "CompleteMonkUpperTrial" });
}

void Setup()
{
    Room = clone_object("/lib/environment/environment.c");
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("energy student");
    User.Race("human");
    User.Str(20);
    User.Int(20);
    User.Dex(20);
    User.Con(20);
    User.Wis(20);
    User.Chr(20);
    User.colorConfiguration("none");
    Lian = clone_object("/guilds/monk/teachers/lian.c");
    Ren = clone_object("/guilds/monk/teachers/ren.c");
    move_object(User, Room);
    move_object(Lian, Room);
    move_object(Ren, Room);
    EnergyLessonsLearned = 0;
}

void CleanUp()
{
    destruct(Ren);
    destruct(Lian);
    destruct(User);
    destruct(Room);
}

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

void PrepareDisciple()
{
    ExpectTrue(User.joinGuild("monk"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/initiates-discipline.c"));
    AdvanceMonk(5);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(User.advanceRank("monk"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/steady-practice.c"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/teachers-recognition.c"));
    AdvanceMonk(10);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/students-awareness.c"));
    ExpectTrue(User.advanceRank("monk"));
    User.spellPoints(10000);
    User.staminaPoints(10000);
}

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
        AdvanceMonk(5 * (index + 1));
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

void TeachEnergyLesson(string path, object tree)
{
    if (!User.isResearched(path))
    {
        foreach (string parent in tree.getParents(path))
        {
            TeachEnergyLesson(parent, tree);
        }
        ExpectTrue(Ren.teachesResearch(path));
        ExpectTrue(User.canResearch(path));
        ExpectFalse(User.initiateResearch(path));
        ExpectTrue(User.learnResearchFrom(Ren, path));
        ExpectTrue(User.isResearched(path));
        EnergyLessonsLearned++;
    }
}

void CheckCatalog(string treePath, string original, int active, int sustained)
{
    object tree = load_object(treePath);
    mapping catalog = tree.getFlattenedResearchTree();
    mapping counts = ([
        "knowledge":0,
        "passive":0,
        "active":0,
        "sustained":0
    ]);
    mapping rankAtLevel = ([
        10:"disciple",
        15:"adept",
        20:"senior disciple",
        30:"master"
    ]);
    mapping names = ([]);
    int newItems = 0;
    ExpectEq(41, sizeof(catalog));
    foreach (object item in m_indices(catalog))
    {
        string path = program_name(item);
        if (item.query("research type") != "tree root")
        {
            string type = item.query("type");
            ExpectFalse(member(names, item.query("name")));
            names[item.query("name")] = path;
            counts[type]++;
            ExpectEq("monk", item.query("source"));
            ExpectEq("points", item.query("research type"));
            ExpectEq(1, item.query("teacher required"));
            ExpectTrue(sizeof(item.query("description")) > 40);
            ExpectTrue(item.query("research cost") >= 1);
            ExpectTrue(item.query("research cost") <= 4);
            ExpectTrue(sizeof(tree.getParents(path)) > 0);
            if (type == "knowledge")
            {
                ExpectTrue(sizeof(item.query("affected research")) > 0 ||
                    sizeof(item.query("related research")) > 0);
            }
            else if (type == "passive")
            {
                ExpectTrue(sizeof(item.query("bonuses")) > 0);
            }
            else
            {
                ExpectTrue(sizeof(item.query("command template")) > 0);
                ExpectTrue(item.query("cooldown") > 0);
                ExpectTrue(item.query("spell point cost") > 0 ||
                    item.query("stamina point cost") > 0);
            }
            if (path != original)
            {
                mapping prerequisites = item.getPrerequisites();
                int level = prerequisites["level"]["value"];
                ExpectEq("guild", prerequisites["monk"]["type"]);
                ExpectEq(({ "monk" }), prerequisites["monk"]["value"]);
                ExpectEq("monk", prerequisites["level"]["guild"]);
                ExpectEq("guild rank", prerequisites["rank"]["type"]);
                ExpectEq(rankAtLevel[level],
                    prerequisites["rank"]["value"][0]);
                foreach (string parent in tree.getParents(path))
                {
                    ExpectEq("research", prerequisites[parent]["type"]);
                }
                ExpectFalse(item.checkPrerequisites(User));
                ExpectFalse(User.initiateResearch(path));
                newItems++;
            }
        }
    }
    ExpectEq(39, newItems);
    ExpectEq(12, counts["knowledge"]);
    ExpectEq(12, counts["passive"]);
    ExpectEq(active, counts["active"]);
    ExpectEq(sustained, counts["sustained"]);
}

void PureChiHasFortyMeaningfulGatedLessons()
{
    CheckCatalog("/guilds/monk/pure-chi.c", Chi + "focused-pulse.c", 12, 4);
}

void ManaShieldHasFortyLessonsWithoutRegisteringItsTrait()
{
    CheckCatalog("/guilds/monk/mana-shield.c",
        Shield + "mindful-ward.c", 11, 5);
    ExpectFalse(load_object("/guilds/monk/mana-shield.c").
        isMemberOfResearchTree(Shield + "ward-trait.c"));
}

void EveryEnergyLessonIsReachableThroughRenAndItsRealDependencies()
{
    PrepareMaster();
    foreach (string treePath in ({
        "/guilds/monk/pure-chi.c", "/guilds/monk/mana-shield.c" }))
    {
        object tree = load_object(treePath);
        mapping catalog = tree.getFlattenedResearchTree();
        int before = EnergyLessonsLearned;
        foreach (object item in m_indices(catalog))
        {
            if (item.query("research type") != "tree root")
            {
                TeachEnergyLesson(program_name(item), tree);
            }
        }
        ExpectEq(40, EnergyLessonsLearned - before);
        foreach (object item in m_indices(catalog))
        {
            ExpectTrue(User.isResearched(program_name(item)));
        }
    }
    ExpectEq(80, EnergyLessonsLearned);
}

void KnowledgeDisplayModifiersHaveRealReceivingMechanics()
{
    foreach (string treePath in ({
        "/guilds/monk/pure-chi.c", "/guilds/monk/mana-shield.c" }))
    {
        mapping catalog = load_object(treePath).getFlattenedResearchTree();
        mapping byName = ([]);
        foreach (object item in m_indices(catalog))
        {
            byName[item.query("name")] = item;
        }
        foreach (object item in m_indices(catalog))
        {
            mapping affected = item.query("affected research");
            if (mappingp(affected))
            {
                foreach (string name in m_indices(affected))
                {
                    object receiver = byName[name];
                    string path = program_name(item);
                    ExpectTrue(objectp(receiver));
                    if (receiver)
                    {
                        string type = item.query("affected research type");
                        if (type == "decrease cost")
                        {
                            mapping spell = receiver.query(
                                "spell point cost modifiers");
                            mapping stamina = receiver.query(
                                "stamina point cost modifiers");
                            if (!mappingp(spell))
                            {
                                spell = ([]);
                            }
                            if (!mappingp(stamina))
                            {
                                stamina = ([]);
                            }
                            ExpectEq(affected[name], (spell + stamina)[path]);
                        }
                        else if (type == "decrease cooldown")
                        {
                            ExpectEq(affected[name],
                                receiver.query("cooldown modifiers")[path]);
                        }
                        else
                        {
                            mapping *modifiers = receiver.query("modifiers");
                            ExpectTrue(sizeof(filter(modifiers,
                                (: $1["type"] == "research" &&
                                    $1["research item"] == $2 :), path)) > 0);
                        }
                    }
                }
            }
        }
    }
}

void NewWardPracticeUsesTheOriginalWardAndNoAdditionalShieldTrait()
{
    mapping catalog = load_object("/guilds/monk/mana-shield.c").
        getFlattenedResearchTree();
    int limited = 0;
    foreach (object item in m_indices(catalog))
    {
        if (item.query("research type") != "tree root" &&
            item.query("type") != "knowledge" &&
            program_name(item) != Shield + "mindful-ward.c")
        {
            ExpectEq(({ Shield + "mindful-ward.c" }),
                item.query("limited by")["research active"]);
            ExpectFalse(item.query("trait"));
            ExpectFalse(item.query("negative trait"));
            ExpectFalse(item.canApplySpecification("ward practice", User));
            limited++;
        }
    }
    ExpectEq(27, limited);
}

void FoundationKnowledgeActuallyChangesSpellPointCosts()
{
    PrepareDisciple();
    ExpectTrue(User.learnResearchFrom(Ren, Chi + "focused-pulse.c"));
    ExpectTrue(User.learnResearchFrom(Ren, Chi + "chi-anatomy.c"));
    object needle = load_object(Chi + "needle-of-chi.c");
    ExpectEq(5, needle.getUsageCosts("", User)["spell point cost"]);
    ExpectFalse(User.initiateResearch(Chi + "economical-breath.c"));
    ExpectTrue(User.learnResearchFrom(Ren, Chi + "economical-breath.c"));
    ExpectEq(4, needle.getUsageCosts("", User)["spell point cost"]);
    ExpectEq(6, load_object(Chi + "focused-pulse.c").
        getUsageCosts("", User)["spell point cost"]);
    ExpectTrue(User.learnResearchFrom(Ren, Shield + "mindful-ward.c"));
    ExpectTrue(User.learnResearchFrom(Ren, Shield + "ward-anatomy.c"));
    object mending = load_object(Shield + "ward-mending.c");
    ExpectEq(8, mending.getUsageCosts("", User)["spell point cost"]);
    ExpectTrue(User.learnResearchFrom(Ren, Shield + "guarded-breath.c"));
    ExpectEq(7, mending.getUsageCosts("", User)["spell point cost"]);
    ExpectEq(10, load_object(Shield + "mindful-ward.c").
        query("stamina point cost"));
}

void WardDependentPassivesAndConversionRequireTheExistingWard()
{
    PrepareDisciple();
    ExpectTrue(User.learnResearchFrom(Ren, Shield + "mindful-ward.c"));
    ExpectTrue(User.learnResearchFrom(Ren, Shield + "ward-anatomy.c"));
    ExpectTrue(User.learnResearchFrom(Ren, Shield + "recovery-cycle.c"));
    ExpectTrue(User.learnResearchFrom(Ren, Shield + "recovery-habit.c"));
    ExpectTrue(User.learnResearchFrom(Ren, Shield + "breath-conversion.c"));
    object habit = load_object(Shield + "recovery-habit.c");
    ExpectFalse(habit.canApplySpecification("bonus heal spell points", User));
    int stamina = User.staminaPoints();
    ExpectFalse(User.executeCommand("chi breath conversion"));
    ExpectEq(stamina, User.staminaPoints());
    ExpectTrue(User.executeCommand("chi mindful ward"));
    ExpectTrue(habit.canApplySpecification("bonus heal spell points", User));
    for (int tick = 0; tick < 4; tick++)
    {
        User.heart_beat();
    }
    User.spellPoints(-20);
    int mana = User.spellPoints();
    stamina = User.staminaPoints();
    ExpectTrue(User.executeCommand("chi breath conversion"));
    ExpectEq(stamina - 12, User.staminaPoints());
    ExpectTrue(User.spellPoints() >= mana + 6);
    ExpectTrue(User.spellPoints() <= mana + 8);
    ExpectTrue(User.blockedByCooldown(Shield + "breath-conversion.c"));
}
