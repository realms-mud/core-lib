//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/tests/support/guilds/monk-trials.h"

object User;
object Guild;

/////////////////////////////////////////////////////////////////////////////
void AdvanceMonkToLevel(int level)
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
void Init()
{
    Guild = load_object("/guilds/monk/monk.c");
    ignoreList += ({ "AdvanceMonkToLevel", "TeachMonkTrialLesson",
        "CompleteMonkUpperTrial" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("student");
    User.Str(20);
    User.Int(20);
    User.Dex(20);
    User.Con(20);
    User.Wis(20);
    User.Chr(20);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
}

/////////////////////////////////////////////////////////////////////////////
void MonkRegistersAsCombatGuildWithExplicitStartingRank()
{
    ExpectTrue(getService("guilds")->isValidGuild("monk"));
    ExpectEq(Guild, getService("guilds")->guildObject("monk"));
    ExpectEq("combat", Guild.guildClass());
    ExpectEq("initiate", Guild.startingRank());
    ExpectEq(1, Guild.costToAdvanceSkillOfType("combat"));
    ExpectEq(2, Guild.costToAdvanceSkillOfType("magic"));
    ExpectEq(({}), Guild.prohibitedGuilds());
}

/////////////////////////////////////////////////////////////////////////////
void MonkPreloadsBeforeWorldContentToPreserveExistingExclusions()
{
    object preload = clone_object(
        "/lib/tests/support/master/preloadHelper.c");
    string *entries = preload.LoadInitFile("init/init_file", ({}));
    ExpectEq("/guilds/monk/monk.c", entries[0]);
    destruct(preload);
}

/////////////////////////////////////////////////////////////////////////////
void RepeatedSetupDoesNotDuplicateMonkBonuses()
{
    Guild.SetupGuild();
    ExpectEq(4, Guild.queryBonus("bonus hit points", 1, "initiate"));
    ExpectEq(3, Guild.queryBonus("bonus spell points", 1, "initiate"));
    ExpectEq(3, Guild.queryBonus("bonus stamina points", 1, "initiate"));
    ExpectEq(20, Guild.queryBonus("bonus hit points", 5, "student"));
}

/////////////////////////////////////////////////////////////////////////////
void JoiningAppliesInitialAwardsAndOpensOnlyFoundationTree()
{
    int hp = User.maxHitPoints();
    int sp = User.maxSpellPoints();
    int stamina = User.maxStaminaPoints();
    ExpectTrue(User.joinGuild("monk"));
    ExpectEq(1, User.guildLevel("monk"));
    ExpectEq("initiate", User.guildRank("monk"));
    ExpectEq(hp + 4, User.maxHitPoints());
    ExpectEq(sp + 3, User.maxSpellPoints());
    ExpectEq(stamina + 3, User.maxStaminaPoints());
    ExpectEq(5, User.AvailableSkillPoints());
    ExpectEq(6, User.researchPoints());
    ExpectEq(({ "/guilds/monk/discipline.c" }),
        User.availableResearchTrees());
    ExpectTrue(User.isResearched("/guilds/monk/discipline/root.c"));
    ExpectFalse(User.joinGuild("monk"));
    ExpectEq(6, User.researchPoints());
}

/////////////////////////////////////////////////////////////////////////////
void ExistingExclusionsWorkInBothJoiningDirections()
{
    ExpectTrue(User.joinGuild("monk"));
    string *paths = ({
        "/guilds/rogue/rogue.c",
        "/guilds/therianthrope/therianthrope.c",
        "/guilds/bard/bard.c"
    });
    foreach(string path in paths)
    {
        object otherGuild = load_object(path);
        ExpectTrue(member(otherGuild.prohibitedGuilds(), "monk") >= 0);
        ExpectFalse(User.joinGuild(otherGuild.guildName()));
    }
    object other = clone_object("/lib/tests/support/services/mockPlayer.c");
    other.Name("other");
    ExpectTrue(other.joinGuild("rogue"));
    ExpectFalse(other.joinGuild("monk"));
    destruct(other);
}

/////////////////////////////////////////////////////////////////////////////
void CompatibleCombatGuildsRemainAllowedInBothDirections()
{
    load_object("/guilds/fighter/fighter.c");
    ExpectTrue(User.joinGuild("monk"));
    ExpectTrue(User.joinGuild("fighter"));
    object other = clone_object("/lib/tests/support/services/mockPlayer.c");
    other.Name("other");
    ExpectTrue(other.joinGuild("fighter"));
    ExpectTrue(other.joinGuild("monk"));
    destruct(other);
}

/////////////////////////////////////////////////////////////////////////////
void RankAdvancementRequiresBothLevelAndFoundationalResearch()
{
    string breath = "/guilds/monk/discipline/disciplined-breath.c";
    ExpectFalse(User.canResearch(breath));
    ExpectTrue(User.joinGuild("monk"));
    ExpectFalse(User.advanceRank("monk"));
    ExpectFalse(User.canResearch(breath));
    AdvanceMonkToLevel(5);
    ExpectFalse(User.advanceRank("monk"));
    ExpectTrue(User.initiateResearch(breath));
    int points = User.researchPoints();
    ExpectFalse(User.initiateResearch(breath));
    ExpectEq(points, User.researchPoints());
    ExpectTrue(User.advanceRank("monk"));
    ExpectEq("student", User.guildRank("monk"));
    ExpectFalse(User.advanceRank("monk"));
    ExpectEq(points, User.researchPoints());
}

/////////////////////////////////////////////////////////////////////////////
void AllRanksAdvanceWithoutArtificialPromotionRewards()
{
    string *ranks = ({ "student", "disciple", "adept",
        "senior disciple", "master candidate", "master" });
    string *items = ({ "disciplined-breath", "students-awareness",
        "disciples-insight", "adepts-focus", "inner-discipline",
        "mastery-of-fundamentals" });
    int trialCosts = 0;
    ExpectTrue(User.joinGuild("monk"));
    for (int index = 0; index < sizeof(ranks); index++)
    {
        AdvanceMonkToLevel(5 * (index + 1));
        string item = sprintf("/guilds/monk/discipline/%s.c", items[index]);
        ExpectFalse(User.advanceRank("monk"));
        ExpectTrue(User.initiateResearch(item));
        if (index == 2)
        {
            object room = clone_object("/lib/environment/environment.c");
            object lian = clone_object("/guilds/monk/teachers/lian.c");
            object ren = clone_object("/guilds/monk/teachers/ren.c");
            move_object(User, room);
            move_object(lian, room);
            move_object(ren, room);
            ExpectFalse(User.advanceRank("monk"));
            ExpectTrue(User.learnResearchFrom(lian,
                "/guilds/monk/discipline/initiates-discipline.c"));
            ExpectTrue(User.learnResearchFrom(lian,
                "/guilds/monk/discipline/steady-practice.c"));
            ExpectTrue(User.learnResearchFrom(lian,
                "/guilds/monk/discipline/teachers-recognition.c"));
            for (int practice = 0; practice < 10; practice++)
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
            move_object(User, this_object());
            destruct(ren);
            destruct(lian);
            destruct(room);
        }
        if (index >= 3)
        {
            object room = clone_object("/lib/environment/environment.c");
            object lian = clone_object("/guilds/monk/teachers/lian.c");
            object ren = clone_object("/guilds/monk/teachers/ren.c");
            move_object(User, room);
            move_object(lian, room);
            move_object(ren, room);
            int before = User.researchPoints();
            CompleteMonkUpperTrial(User, lian, ren, index - 3);
            trialCosts += before - User.researchPoints();
            move_object(User, this_object());
            destruct(ren);
            destruct(lian);
            destruct(room);
        }
        int points = User.researchPoints();
        ExpectTrue(User.advanceRank("monk"));
        ExpectEq(ranks[index], User.guildRank("monk"));
        ExpectEq(points, User.researchPoints());
        ExpectFalse(User.advanceRank("monk"));
    }
    ExpectEq(26 - trialCosts, User.researchPoints());
    ExpectEq(150, User.AvailableSkillPoints());
    ExpectTrue(User.demoteRank("monk"));
    ExpectEq("master candidate", User.guildRank("monk"));
    ExpectTrue(User.advanceRank("monk"));
    ExpectEq("master", User.guildRank("monk"));
}

/////////////////////////////////////////////////////////////////////////////
void HigherResearchRequiresRankNotOnlyLevel()
{
    ExpectTrue(User.joinGuild("monk"));
    AdvanceMonkToLevel(10);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    string awareness = "/guilds/monk/discipline/students-awareness.c";
    ExpectFalse(User.canResearch(awareness));
    ExpectTrue(User.advanceRank("monk"));
    ExpectTrue(User.canResearch(awareness));
}

/////////////////////////////////////////////////////////////////////////////
void LeavingRetainsKnowledgeButBlocksNewMonasticResearch()
{
    string breath = "/guilds/monk/discipline/disciplined-breath.c";
    ExpectTrue(User.joinGuild("monk"));
    AdvanceMonkToLevel(5);
    ExpectTrue(User.initiateResearch(breath));
    int bonus = User.researchBonusTo("BonusHealStaminaRate");
    ExpectTrue(bonus > 0);
    ExpectTrue(User.leaveGuild("monk"));
    ExpectFalse(User.memberOfGuild("monk"));
    ExpectTrue(User.isResearched(breath));
    ExpectEq(bonus, User.researchBonusTo("BonusHealStaminaRate"));
    ExpectFalse(User.canResearch(
        "/guilds/monk/discipline/students-awareness.c"));
    ExpectFalse(User.advanceRank("monk"));
}

/////////////////////////////////////////////////////////////////////////////
void RejoiningUsesExistingDelayRankResetAndProbationWithoutNewAwards()
{
    string breath = "/guilds/monk/discipline/disciplined-breath.c";
    ExpectTrue(User.joinGuild("monk"));
    AdvanceMonkToLevel(5);
    ExpectTrue(User.initiateResearch(breath));
    ExpectTrue(User.advanceRank("monk"));
    int skillPoints = User.AvailableSkillPoints();
    int researchPoints = User.researchPoints();
    ExpectTrue(User.leaveGuild("monk"));
    ExpectFalse(User.joinGuild("monk"));
    User.agePlayer(Guild.outcastUntilDelay());
    ExpectTrue(User.joinGuild("monk"));
    ExpectEq(5, User.guildLevel("monk"));
    ExpectEq("initiate", User.guildRank("monk"));
    ExpectTrue(User.isResearched(breath));
    ExpectEq(skillPoints, User.AvailableSkillPoints());
    ExpectEq(researchPoints, User.researchPoints());
    ExpectTrue(User.isAnathema("monk"));
    ExpectFalse(User.advanceRank("monk"));
    User.agePlayer(86401);
    ExpectTrue(User.advanceRank("monk"));
    ExpectEq("student", User.guildRank("monk"));
}
