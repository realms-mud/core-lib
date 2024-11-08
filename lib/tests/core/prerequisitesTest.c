//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Researcher;
object Prerequisite;
object Configuration;
string colorConfiguration;

/////////////////////////////////////////////////////////////////////////////
void PopulatePrerequisites()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("level", (["type":"level", "guild" : "mage", "value": 10])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("long sword", (["type":"skill", "value": 10])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("strength", (["type":"attribute", "value" : 10])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("fetch a pencil", (["type":"quest" ])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("test research", (["type":"research"])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("race", (["type":"race", "value": ({ "elf", "high elf", "half elf" }) ])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("guild", (["type":"guild", "value": ({ "mage" }) ])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("best kill", (["type":"combat statistic", "value": 10 ])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("orc", (["type":"combat statistic", "value": 10])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("annoying", (["type":"trait", "value": ({ "boorish", "loutish" })])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("nifty", (["type":"trait", "value" : ({ "spiffy" })])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("background", (["type":"background", "value" : ({ "test" })])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("faction", (["type":"faction", "value" : ({ "test" })])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("opinion", (["type":"opinion", "value": 20])));
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "PopulatePrerequisites" });

    colorConfiguration = "3-bit";
    Configuration = load_object("/lib/dictionaries/configurationDictionary.c");
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Researcher = clone_object("/lib/tests/support/services/combatWithMockServices");
    Researcher.Name("Bob");

    Prerequisite = clone_object("/lib/tests/support/research/prerequisiteItem");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Prerequisite);
    destruct(Researcher);
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidPrerequisite()
{
    ExpectFalse(Prerequisite.AddTestPrerequisite("some key", ([ "type": "blah", "value": 10 ]) ));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddValidPrerequisite()
{
    PopulatePrerequisites();
}

/////////////////////////////////////////////////////////////////////////////
void CanAddValidPrerequisitesByGrouping()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("level", (["type":"level", "guild" : "mage", "value" : 10]), "group a"));
    ExpectTrue(Prerequisite.AddTestPrerequisite("level", (["type":"level", "guild" : "mage", "value" : 15]), "group b"));
    ExpectEq("([ group a: ([ level: ([ guild: mage, type: level, value: 10, ]), ]), group b: ([ level: ([ guild: mage, type: level, value: 15, ]), ]), ])", Prerequisite.getPrerequisites());
}

/////////////////////////////////////////////////////////////////////////////
void GetPrerequisitesReturnsCorrectValue()
{
    string expected = "([ annoying: ([ type: trait, value: ({ boorish, loutish, }), ]), background: ([ type: background, value: ({ test, }), ]), best kill: ([ type: combat statistic, value: 10, ]), faction: ([ type: faction, value: ({ test, }), ]), fetch a pencil: ([ type: quest, ]), guild: ([ type: guild, value: ({ mage, }), ]), level: ([ guild: mage, type: level, value: 10, ]), long sword: ([ type: skill, value: 10, ]), nifty: ([ type: trait, value: ({ spiffy, }), ]), opinion: ([ type: opinion, value: 20, ]), orc: ([ type: combat statistic, value: 10, ]), race: ([ type: race, value: ({ elf, half elf, high elf, }), ]), strength: ([ type: attribute, value: 10, ]), test research: ([ type: research, ]), ])";
    PopulatePrerequisites();
    ExpectEq(expected, Prerequisite.getPrerequisites());
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesSucceedsWhenNoPrerequisites()
{
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher));
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesLevelChecks()
{
    Researcher.ToggleMockGuilds();
    Researcher.SetLevel(10);
    ExpectTrue(Prerequisite.AddTestPrerequisite("level", (["type":"level", "guild" : "mage", "value" : 10])));
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check initially fails");

    Researcher.SetGuild("fighter");
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check fails when wrong guild set");

    Researcher.SetGuild("mage");
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "check succeeds when guild set");
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesGuildChecks()
{
    Researcher.ToggleMockGuilds();
    ExpectTrue(Prerequisite.AddTestPrerequisite("guild", (["type":"guild", "value" : ({ "mage" })])));
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check initially fails");

    Researcher.SetGuild("fighter");
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check fails when wrong guild set");

    Researcher.SetGuild("mage");
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "check succeeds when guild set");
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesGuildRankChecks()
{
    Researcher.ToggleMockGuilds();
    ExpectTrue(Prerequisite.AddTestPrerequisite("guild rank", 
        (["type": "guild rank", "guild": "mage", "value" : ({ "adept", "archmage" })])));

    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check initially fails");

    Researcher.SetGuild("fighter");
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check fails when wrong guild set");

    Researcher.SetGuild("mage");
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check fails when correct guild set");

    Researcher.SetRank("acolyte");
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check fails when wrong rank set");

    Researcher.SetRank("adept");
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "check succeeds when valid rank set");

    Researcher.SetRank("archmage");
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher));
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesRaceChecks()
{
    Researcher.ToggleMockGuilds();
    ExpectTrue(Prerequisite.AddTestPrerequisite("race", (["type":"race", "value" : ({ "elf", "high elf", "half elf" })])));
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check initially fails");

    Researcher.Race("dwarf");
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check fails when wrong race set");

    Researcher.Race("elf");
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "check succeeds when elf set");

    Researcher.Race("high elf");
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "check succeeds when high elf set");

    Researcher.Race("half elf");
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "check succeeds when half elf set");
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesSkillChecks()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("long sword", (["type":"skill", "value" : 10])));
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check initially fails");

    Researcher.Str(20);
    Researcher.addSkillPoints(20);
    Researcher.advanceSkill("long sword", 8);
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "skill level at 8");
    Researcher.advanceSkill("long sword", 2);
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "skill level raised to 10");
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesResearchChecks()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("/lib/tests/support/research/testGrantedResearchItem.c",
        (["type":"research"])));
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check initially fails");

    Researcher.ToggleMockResearch();
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "item researched");
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesEquivalentResearchChecks()
{
    destruct(Researcher);
    Researcher = clone_object("/lib/tests/support/services/researchWithMockServices");
    Researcher.Name("Bob");
    Researcher.addResearchPoints(2);

    ExpectTrue(Prerequisite.AddTestPrerequisite("/lib/tests/support/research/testResearchA.c",
        (["type":"research"])));
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check initially fails");

    ExpectTrue(Researcher.initiateResearch(
        "/lib/tests/support/research/equivalenceItem.c"), "initiate research");

    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "item researched");
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesAttributeChecks()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("wisdom", (["type":"attribute", "value": 10])));
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check initially fails");

    Researcher.Wis(8);
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "wisdom at 8");
    Researcher.Wis(20);
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "wisdom raised to 20");
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesQuestChecks()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("fetch a pencil", (["type":"quest"])));
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check initially fails");

    Researcher.ToggleMockQuests();
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "quest completed");
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesFactionChecks()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("faction", (["type":"faction", "value": ({ "test" })])));
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check initially fails");

    Researcher.ToggleMockFaction();
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "target belongs to the faction");
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesTraitsChecks()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("trait", (["type":"trait", "value" : ({ "boorish", "loutish" })])));
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check initially fails");

    Researcher.ToggleMockTrait();

    Researcher.addTrait("boorish");
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "target only has 'boorish' trait");

    Researcher.addTrait("loutish");
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "target has both traits");

    Researcher.removeTrait("boorish");
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "target only has 'loutish' trait");
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesMultipleTraitsChecks()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("annoying", (["type":"trait", "value" : ({ "boorish", "loutish" })])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("nifty", (["type":"trait", "value" : ({ "spiffy" })])));
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check initially fails");

    Researcher.ToggleMockTrait();

    Researcher.addTrait("boorish");
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "target only has 'boorish' trait");

    Researcher.addTrait("spiffy");
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "target has both traits");
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesBackgroundChecks()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("background", (["type":"background", "value" : ({ "test" })])));
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check initially fails");

    Researcher.ToggleMockBackground();
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "target has background trait");
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesGroupings()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("long sword", (["type":"skill", "value" : 5]), "group a"));
    ExpectTrue(Prerequisite.AddTestPrerequisite("long sword", (["type":"skill", "value" : 10]), "group b"));
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher, "group a"), "check initially fails for group a");
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher, "group b"), "check initially fails for group b");

    Researcher.Str(20);
    Researcher.addSkillPoints(100);
    Researcher.advanceSkill("long sword", 8);
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher, "group a"), "check for group a succeeds at skill of 8");
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher, "group b"), "checkfor group b fails at skill of 8");

    Researcher.advanceSkill("long sword", 3);
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher, "group a"), "check for group a succeeds at skill of 11");
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher, "group b"), "check for group b succeeds at skill of 11");
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesOpinionChecks()
{
    object owner = clone_object("/lib/realizations/npc.c");
    destruct(Researcher);
    Researcher = clone_object("/lib/realizations/player.c");
    Researcher.Name("Bob");

    ExpectTrue(Prerequisite.AddTestPrerequisite("opinion", (["type":"opinion", "value" : 20]), "group a"));
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher, "group a", owner), "check initially fails for group a");

    Researcher.addTrait("/lib/instances/traits/educational/articulate.c");
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher, "group a", owner), "check passes for group a");
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesPresenceChecks()
{
    object owner = clone_object("/lib/realizations/npc.c");
    owner.Name("Fred");
    destruct(Researcher);
    Researcher = clone_object("/lib/realizations/player.c");
    Researcher.Name("Bob");

    move_object(Researcher, this_object());

    ExpectTrue(Prerequisite.AddTestPrerequisite("presence", (["type":"presence", "value" : ({ "Fred" }) ]), "group a"));
    move_object(owner, this_object());
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher, "group a", owner), "check passes when present");

    destruct(owner);
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher, "group a", owner), "check fails when not present");
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesNotPresentChecks()
{
    object owner = clone_object("/lib/realizations/npc.c");
    owner.Name("Fred");
    destruct(Researcher);
    Researcher = clone_object("/lib/realizations/player.c");
    Researcher.Name("Bob");

    move_object(Researcher, this_object());

    ExpectTrue(Prerequisite.AddTestPrerequisite("not present", 
        (["type":"not present", "value" : ({ "Fred" })]), "group a"));

    move_object(owner, this_object());
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher, "group a", owner), "check fails when present");

    destruct(owner);
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher, "group a", owner), "check passes when not present");
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesSpokenTopicChecks()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("spoken topics",
        (["type": "spoken topics", "value": ({ "start quest" })])));

    ExpectFalse(Prerequisite.checkPrerequisites(Researcher, 0, Researcher), "check fails when not spoken");
    Researcher.ToggleMockConversations();
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher, 0, Researcher), "check passes when spoken");
}

/////////////////////////////////////////////////////////////////////////////
void DisplayPrerequisitesCorrectlyDisplaysQuestPrerequisites()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("/lib/tests/support/quests/fakeQuestItem.c",
        ([ "type":"quest"])));

    ExpectEq("\x1b[0;36mPrerequisites:\n"
        "\x1b[0m\x1b[0;33m          Quest: \x1b[0m\x1b[0;35mHail to the king, baby!\n\x1b[0m", 
        Prerequisite.displayPrerequisites(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayPrerequisitesCorrectlyDisplaysResearchPrerequisites()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("/lib/tests/support/research/testGrantedResearchItem.c",
        (["type":"research"])));

    ExpectEq("\x1b[0;36mPrerequisites:\n"
        "\x1b[0m\x1b[0;33m       Research: \x1b[0m\x1b[0;35mGranted Research\n\x1b[0m",
        Prerequisite.displayPrerequisites(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayPrerequisitesCorrectlyDisplaysTraitPrerequisites()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("trait", ([
        "type": "trait", 
        "value" : ({ "/lib/instances/traits/personality/abrasive.c", 
            "/lib/instances/traits/personality/charming.c" })
    ])));

    ExpectEq("\x1b[0;36mPrerequisites:\n"
        "\x1b[0m\x1b[0;33m          Trait: \x1b[0m\x1b[0;35mAbrasive or Charming\n\x1b[0m",
        Prerequisite.displayPrerequisites(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayPrerequisitesCorrectlyDisplaysAttributePrerequisites()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("wisdom", ([
        "type":"attribute", "value": 10])));

    ExpectEq("\x1b[0;36mPrerequisites:\n\x1b[0m\x1b[0;33m      Attribute: \x1b[0m\x1b[0;35mWisdom of 10\n\x1b[0m",
        Prerequisite.displayPrerequisites(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayPrerequisitesCorrectlyDisplaysSkillPrerequisites()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("long sword", ([
        "type":"skill", "value" : 10])));

    ExpectEq("\x1b[0;36mPrerequisites:\n\x1b[0m\x1b[0;33m          Skill: \x1b[0m\x1b[0;35mLong sword of 10\n\x1b[0m",
        Prerequisite.displayPrerequisites(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayPrerequisitesCorrectlyDisplaysLevelPrerequisites()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("level", ([
        "type":"level", "value": 10])));

    ExpectEq("\x1b[0;36mPrerequisites:\n\x1b[0m\x1b[0;33m          Level: \x1b[0m\x1b[0;35mLevel of 10\n\x1b[0m",
        Prerequisite.displayPrerequisites(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayPrerequisitesCorrectlyDisplaysLevelWithGuildPrerequisites()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("level", ([
        "type":"level", "value": 10, "guild":"mage"])));

    ExpectEq("\x1b[0;36mPrerequisites:\n\x1b[0m\x1b[0;33m          Level: \x1b[0m\x1b[0;35mLevel of 10 in Mage\n\x1b[0m",
        Prerequisite.displayPrerequisites(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayPrerequisitesCorrectlyDisplaysRacePrerequisites()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("race", ([
        "type":"race", "value" : ({ "elf", "half-elf", "high elf" }) ])));

    ExpectEq("\x1b[0;36mPrerequisites:\n\x1b[0m"
        "\x1b[0;33m           Race: \x1b[0m\x1b[0;35mElf or Half-elf or High Elf\n\x1b[0m",
        Prerequisite.displayPrerequisites(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayPrerequisitesCorrectlyDisplaysGuildPrerequisites()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("guild", ([
        "type":"guild", "value": ({ "fighter", "thief" })])));

    ExpectEq("\x1b[0;36mPrerequisites:\n\x1b[0m\x1b[0;33m          Guild: \x1b[0m\x1b[0;35mFighter or Thief\n\x1b[0m",
        Prerequisite.displayPrerequisites(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayPrerequisitesCorrectlyDisplaysGuildRankPrerequisites()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("guild rank",
        (["type":"guild rank", "guild" : "mage", "value" : ({ "adept", "archmage" })])));

    ExpectEq("\x1b[0;36mPrerequisites:\n\x1b[0m\x1b[0;33m     Guild rank: "
        "\x1b[0m\x1b[0;35mRank in the mage guild of Adept or Archmage\n\x1b[0m",
        Prerequisite.displayPrerequisites(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayPrerequisitesCorrectlyDisplaysFactionPrerequisites()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("faction", ([
        "type":"faction", "value": ({ "llama lords" })])));

    ExpectEq("\x1b[0;36mPrerequisites:\n\x1b[0m\x1b[0;33m        Faction: \x1b[0m\x1b[0;35mLlama Lords\n\x1b[0m",
        Prerequisite.displayPrerequisites(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayPrerequisitesCorrectlyDisplaysCombatStatisticPrerequisites()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("orc", (["type":"combat statistic", "value" : 2])));

    ExpectEq("\x1b[0;36mPrerequisites:\n\x1b[0m\x1b[0;33mCombat statistic: \x1b[0m\x1b[0;35mOrc kill count of 2\n\x1b[0m",
        Prerequisite.displayPrerequisites(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayPrerequisitesCorrectlyDisplaysBestKillPrerequisites()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("best kill", (["type":"combat statistic", "value" : 10])));

    ExpectEq("\x1b[0;36mPrerequisites:\n\x1b[0m\x1b[0;33mCombat statistic: \x1b[0m\x1b[0;35mBest kill level is 10\n\x1b[0m",
        Prerequisite.displayPrerequisites(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayPrerequisitesCorrectlyDisplaysOpinionWithOpinionPrerequisites()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("opinion", ([
        "type":"opinion", "value": 10 ])));

    ExpectEq("\x1b[0;36mPrerequisites:\n\x1b[0m\x1b[0;33m        Opinion: \x1b[0m\x1b[0;35mOpinion of 10\n\x1b[0m",
        Prerequisite.displayPrerequisites(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayPrerequisitesCorrectlyDisplaysPresenceWithPresencePrerequisites()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("presence", 
        (["type": "presence", "value" : ({ "Fred" })])));

    ExpectEq("\x1b[0;36mPrerequisites:\n\x1b[0m\x1b[0;33m       Presence: \x1b[0m\x1b[0;35mFred\n\x1b[0m",
        Prerequisite.displayPrerequisites(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayPrerequisitesCorrectlyDisplaysEquivalence()
{
    getDictionary("research").researchObject("/lib/tests/support/research/testResearchA.c");    
    getDictionary("research").researchObject("/lib/tests/support/research/equivalenceItem.c");
    object researchItem = getDictionary("research").researchObject(
        "/lib/tests/support/research/testResearchPrereq.c");

    ExpectEq("\x1b[0;36mPrerequisites:\n\x1b[0m\x1b[0;33m       Research: "
        "\x1b[0m\x1b[0;35mWeasel Inversion\n"
        "\x1b[0m\x1b[0;35m                 Equivalent: \x1b[0m"
        "\x1b[0;34mWeasel Blathering\n\x1b[0m",
        researchItem.displayPrerequisites(colorConfiguration, Configuration));
}
