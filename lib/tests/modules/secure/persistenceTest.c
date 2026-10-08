//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

#include "/lib/include/inventory.h"

object Player;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database.PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(database.Gorthaur());
    dataAccess.savePlayerData(database.GetWizardOfLevel("elder"));

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/realizations/player.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    // Need to clean up database stuff and the cost of doing a PrepDatabase for each
    // test is pretty high.
    object *items = all_inventory(Player);
    if (sizeof(items))
    {
        foreach(object item in items)
        {
            if (function_exists("unequip", item))
            {
                item.unequip(item.query("name"), 1);
            }
            destruct(item);
        }
        Player.save();
    }
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerMaterialAttributesRestored()
{
    move_object(Player, "/lib/tests/support/environment/fakeEnvironment.c");

    Player.restore("gorthaur");
    ExpectEq("Gorthaur", Player.Name());
    ExpectEq("male", Player.Gender());
    ExpectEq(1, Player.Age());
    ExpectEq(0, Player.Ghost());
    ExpectEq(0, Player.Invisibility());
    ExpectEq("is now here", Player.MessageIn());
    ExpectEq("leaves", Player.MessageOut());
    ExpectEq("blah", Player.MagicalMessageIn());
    ExpectEq("de-blahs", Player.MagicalMessageOut());
    ExpectEq("blarg", Player.MessageHome());
    ExpectEq("does stuff", Player.MessageClone());
    ExpectEq("the title-less", Player.Title());
    ExpectEq("Weasel Lord", Player.Pretitle());
    ExpectEq("blah", Player.short());
    ExpectEq("This is a long description", Player.description());
    ExpectTrue(Player.creationDate());
    ExpectEq(StartLocation(), Player.savedLocation());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerAttributesRestored()
{
    Player.restore("gorthaur");
    ExpectEq(10, Player.attributeValue("strength", 1));
    ExpectEq(11, Player.attributeValue("intelligence", 1));
    ExpectEq(12, Player.attributeValue("dexterity", 1));
    ExpectEq(13, Player.attributeValue("wisdom", 1));
    ExpectEq(14, Player.attributeValue("constitution", 1));
    ExpectEq(15, Player.attributeValue("charisma", 1));
    ExpectEq(1, Player.attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerBiologicalAttributesRestored()
{
    Player.restore("gorthaur");
    ExpectEq(5, Player.Intoxicated());
    ExpectEq(2, Player.Soaked());
    ExpectEq(4, Player.Stuffed());
    ExpectEq(3, Player.Drugged());
    ExpectEq(1, Player.haveHeadache());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCombatAttributesRestored()
{
    Player.restore("gorthaur");
    ExpectEq(100, Player.hitPoints());
    ExpectEq(200, Player.maxHitPoints());
    ExpectEq(120, Player.spellPoints());
    ExpectEq(235, Player.maxSpellPoints());
    ExpectEq(140, Player.staminaPoints());
    ExpectEq(150 + (3 * Player.Con()) + (3 * Player.Str()),
        Player.maxStaminaPoints());
    ExpectEq(70, Player.Wimpy());
    ExpectTrue(Player.onKillList());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerGuildsRestored()
{
    Player.restore("gorthaur");
    ExpectEq(({ "fake mage", "blarg" }), Player.memberOfGuilds());
    ExpectEq(22, Player.effectiveLevel());
    ExpectEq(120587, Player.effectiveExperience());
    ExpectEq(16, Player.guildLevel("fake mage"));
    ExpectEq(133, Player.guildExperience("fake mage"));
    ExpectEq("acolyte", Player.guildRank("fake mage"));
    ExpectEq("the blah blah", Player.guildTitle("fake mage"));
    ExpectEq("Mage", Player.guildPretitle("fake mage"));
    ExpectFalse(Player.isAnathema("fake mage"));
    ExpectEq(2333, Player.ageWhenRankAdvanced("fake mage"));

    // Even though the guild level for fighter is 5, since they left,
    // it's effectively 0.
    ExpectEq(0, Player.guildLevel("fake fighter"));
    ExpectTrue(Player.isAnathema("fake fighter"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerQuestsRestored()
{
    Player.restore("gorthaur");
    ExpectEq(({ "/lib/tests/support/quests/fakeQuestItem.c" }), Player.activeQuests());

    object quest = load_object("/lib/tests/support/quests/fakeQuestItem.c");
    ExpectEq(sprintf("\x1b[0;36m%s\x1b[0m", "I've been asked to meet the king! I met King Tantor the Unclean of Thisplace. He seems to like me. The king asked me - ME - to be his personal manservant. Yay me!"),
        Player.questStory("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerRaceRestored()
{
    Player.restore("gorthaur");
    ExpectEq("elf", Player.Race());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerResearchRestored()
{
    Player.restore("gorthaur");
    ExpectEq(3, Player.researchPoints());
    ExpectTrue(Player.isResearched("/lib/tests/support/research/testGrantedResearchItem.c"));
    ExpectTrue(Player.isResearched("/lib/tests/support/research/testSustainedResearchItem.c"));
    ExpectEq(({ "/lib/tests/support/research/testSecondResearchTree.c", 
        "/lib/tests/support/research/testBlargTree.c",
        "/lib/tests/support/research/testConstructedTree.c"}), Player.availableResearchTrees());
    ExpectTrue(Player.selectResearchChoice("/lib/tests/support/research/testPersistedActiveTraitResearch.c",
        "Test", "1"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerExperiencesRestored()
{
    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");

    mapping *observations = dataAccess.queryObservationsByPlayer("gorthaur",
        ([]), 0, 0);

    ExpectEq(1, sizeof(observations));
    ExpectEq("combat.kill", observations[0]["type"]);
    ExpectEq("orc marauder", observations[0]["subject"]);
    ExpectEq(142, observations[0]["metadata"]["damage"]);
    ExpectEq("snow", observations[0]["context"]["weather"]);

    ExpectTrue(dataAccess.hasObservationByPlayer("gorthaur",
        ([ "type": "combat.kill" ])));
    ExpectEq(1, dataAccess.countObservationsByPlayer("gorthaur",
        ([ "type": "combat" ])));

    mapping *filtered = dataAccess.queryObservationsByPlayer("gorthaur",
        ([ "type": "combat.kill", "weather": "snow", "weapon": "katana" ]),
        0, 0);
    ExpectEq(1, sizeof(filtered));

    destruct(dataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerRelationshipsRestored()
{
    string targetKey = "/lib/realizations/monster#fred";

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");

    ExpectTrue(dataAccess.hasRelationshipByPlayerAndTarget("gorthaur",
        targetKey));
    ExpectEq(5, dataAccess.relationshipDimensionByPlayerAndTarget("gorthaur",
        targetKey, "trust"));
    ExpectEq(2, dataAccess.relationshipDimensionByPlayerAndTarget("gorthaur",
        targetKey, "respect"));
    ExpectEq(1, sizeof(dataAccess.relationshipHistoryByPlayerAndTarget(
        "gorthaur", targetKey, ([]))));

    destruct(dataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerSkillsRestored()
{
    Player.restore("gorthaur");
    ExpectEq(16, Player.getSkill("long sword"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerMoneyRestored()
{
    Player.restore("gorthaur");
    ExpectEq(12345, Player.Money());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerTraitsRestored()
{
    Player.restore("gorthaur");
    ExpectEq(({ "/lib/tests/support/traits/testTrait.c", 
        "/lib/tests/support/traits/testTraitWithDuration.c" }), 
        Player.Traits());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerFactionsRestored()
{
    Player.restore("gorthaur");
    ExpectTrue(Player.memberOfFaction("/lib/tests/support/factions/badGuys.c"));
    ExpectFalse(Player.memberOfFaction("/lib/tests/support/factions/goodGuys.c"));
    ExpectEq("admiring", Player.factionDispositionToward("/lib/tests/support/factions/badGuys.c"));
    ExpectEq("fearful", Player.factionDispositionToward("/lib/tests/support/factions/goodGuys.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerMaterialAttributesSaved()
{
    Player.restore("gorthaur");
    Player.Invisibility(1);
    Player.Gender("female");
    Player.MessageIn("a");
    Player.MessageOut("b");
    Player.MagicalMessageIn("c");
    Player.MagicalMessageOut("d");
    Player.MessageHome("e");
    Player.MessageClone("f");
    Player.Title("g");
    Player.Pretitle("h");
    Player.short("i");
    Player.description("j");
    Player.save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    move_object(Player, "/lib/tests/support/environment/fakeEnvironment.c");
    ExpectEq("Gorthaur", Player.Name());
    ExpectEq("female", Player.Gender());
    ExpectTrue(Player.Invisibility());
    ExpectEq("a", Player.MessageIn());
    ExpectEq("b", Player.MessageOut());
    ExpectEq("c", Player.MagicalMessageIn());
    ExpectEq("d", Player.MagicalMessageOut());
    ExpectEq("e", Player.MessageHome());
    ExpectEq("f", Player.MessageClone());
    ExpectEq("g", Player.Title());
    ExpectEq("h", Player.Pretitle());
    Player.Invisibility(1);
    ExpectEq("i", Player.short());
    ExpectEq("j", Player.description());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerAttributesSaved()
{
    Player.restore("gorthaur");
    Player.Str(6);
    Player.Int(7);
    Player.Dex(8);
    Player.Wis(9);
    Player.Con(10);
    Player.Chr(11);
    Player.addAttributePointsToSpend(4);
    Player.save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");

    ExpectEq(6, Player.attributeValue("strength", 1));
    ExpectEq(7, Player.attributeValue("intelligence", 1));
    ExpectEq(8, Player.attributeValue("dexterity", 1));
    ExpectEq(9, Player.attributeValue("wisdom", 1));
    ExpectEq(10, Player.attributeValue("constitution", 1));
    ExpectEq(11, Player.attributeValue("charisma", 1));
    ExpectEq(5, Player.attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerBiologicalAttributesSaved()
{
    Player.restore("gorthaur");
    Player.addIntoxication(2);
    Player.addStuffed(2);
    Player.addDrugged(2);
    Player.addSoaked(2);
    Player.save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectEq(7, Player.Intoxicated());
    ExpectEq(4, Player.Soaked());
    ExpectEq(6, Player.Stuffed());
    ExpectEq(5, Player.Drugged());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCombatAttributesSaved()
{
    Player.restore("gorthaur");
    ExpectEq(100, Player.hitPoints());
    ExpectEq(120, Player.spellPoints());
    ExpectEq(140, Player.staminaPoints());
    ExpectEq(70, Player.Wimpy());
    ExpectTrue(Player.onKillList());
    Player.hitPoints(10);
    Player.spellPoints(10);
    Player.staminaPoints(10);
    Player.Wimpy("40");
    Player.toggleKillList();
    Player.save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectEq(110, Player.hitPoints());
    ExpectEq(130, Player.spellPoints());
    ExpectEq(150, Player.staminaPoints());
    ExpectEq(40, Player.Wimpy());
    ExpectFalse(Player.onKillList());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerGuildsSaved()
{
    object dict = getService("guilds");
    object mage = load_object("/lib/tests/support/guilds/mageGuild.c");
    object blarg = load_object("/lib/tests/support/guilds/blargGuild.c");

    object guild = load_object("/lib/tests/support/guilds/testGuild.c");

    Player.restore("gorthaur");
    ExpectTrue(Player.joinGuild("test"));
    Player.addExperience(2000);
    Player.save();
    ExpectTrue(Player.memberOfGuild("test"));

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");

    ExpectEq(122082, Player.effectiveExperience());
    ExpectTrue(Player.memberOfGuild("test"));
    ExpectEq(1,Player.guildLevel("test"));
    ExpectEq("neophyte", Player.guildRank("test"));
    ExpectEq(101, Player.guildExperience("test"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerQuestsSaved()
{
    Player.restore("gorthaur");
    Player.advanceQuestState("/lib/tests/support/quests/fakeQuestItem.c", "king is dead");
    Player.save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");

    ExpectEq(({ "/lib/tests/support/quests/fakeQuestItem.c" }), Player.completedQuests());

    object quest = load_object("/lib/tests/support/quests/fakeQuestItem.c");
    ExpectEq(sprintf("\x1b[0;36m%s\x1b[0m\x1b[0;31;1m%s\x1b[0m", "I've been "
        "asked to meet the king! I met King Tantor the Unclean of Thisplace. "
        "He seems to like me. The king asked me - ME - to be his personal "
        "manservant. Yay me! I must lay off the sauce - and the wenches. King "
        "Tantor is dead because of my night of debauchery.", " [Failure]"),
        Player.questStory("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerRaceSaved()
{
    Player.restore("gorthaur");
    ExpectEq("elf", Player.Race());
    Player.Race("dwarf");
    Player.save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectEq("dwarf", Player.Race());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerResearchSaved()
{
    Player.restore("gorthaur");
    ExpectEq(4, Player.researchPoints());
    ExpectTrue(Player.isResearched("/lib/tests/support/research/testGrantedResearchItem.c"));
    ExpectTrue(Player.isResearched("/lib/tests/support/research/testSustainedResearchItem.c"));
    ExpectEq (({ "/lib/tests/support/research/testSecondResearchTree.c", 
        "/lib/tests/support/research/testBlargTree.c",
        "/lib/tests/support/research/testConstructedTree.c" }),
        Player.availableResearchTrees());
    ExpectTrue(Player.selectResearchChoice("/lib/tests/support/research/testPersistedActiveTraitResearch.c",
        "Test", "1"));
    Player.initiateResearch("/lib/tests/support/research/testPointsResearchItem.c");
    Player.save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectEq(3, Player.researchPoints());
    ExpectTrue(Player.isResearched("/lib/tests/support/research/testPointsResearchItem.c"));
    ExpectTrue(Player.isResearched("/lib/tests/support/research/testPersistedActiveTraitResearch.c"));
    ExpectTrue(Player.isResearched("/lib/tests/support/research/testSustainedResearchItem.c"));
    ExpectTrue(Player.sustainedResearchIsActive("/lib/tests/support/research/testSustainedResearchItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerExperiencesSaved()
{
    Player.restore("gorthaur");
    mapping recorded = Player.recordObservation(([
        "type": "movement.enter",
        "subject": "tol-dhurath temple",
        "participants": ({ }),
        "timestamp": 1234,
        "location": "/areas/tol-dhurath/entry/1x0.c",
        "context": ([
            "terrain": "forest",
            "details": ([ "wind": "north", "conditions": ({ "snow", "ice" }) ])
        ]),
        "metadata": ([
            "speed": "walk",
            "measurements": ({ "slow", 2 })
        ])
    ]));
    ExpectTrue(Player.hasObservation(([ "type": "combat.kill" ])));

    recorded["context"]["details"]["wind"] = "east";
    recorded["metadata"]["measurements"][0] = "fast";

    Player.save();

    object restoredPlayer = clone_object("/lib/realizations/player.c");
    restoredPlayer.restore("gorthaur");

    ExpectTrue(restoredPlayer.hasObservation(([
        "type": "movement.enter", "terrain": "forest" ])));
    mapping *observations = restoredPlayer.queryObservations(([
        "type": "movement.enter" ]));
    ExpectEq(recorded["ID"], observations[0]["ID"]);
    ExpectEq("north", observations[0]["context"]["details"]["wind"]);
    ExpectEq(({ "snow", "ice" }),
        observations[0]["context"]["details"]["conditions"]);
    ExpectEq(({ "slow", 2 }), observations[0]["metadata"]["measurements"]);
    ExpectEq(1, restoredPlayer.countObservations(([
        "type": "movement.enter",
        "context": ([ "details": ([ "wind": "north" ]) ])
    ])));
    ExpectTrue(restoredPlayer.hasObservation(([ "type": "combat.kill" ])));
    restoredPlayer.restore("gorthaur");
    ExpectEq(1, restoredPlayer.countObservations(([
        "type": "movement.enter",
        "timestamp": 1234
    ])));

    destruct(restoredPlayer);
}

/////////////////////////////////////////////////////////////////////////////
void ExperiencesV2CodecPreservesScalarsAndDelimiters()
{
    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    mapping context = ([
        "": "",
        "note##:=:": "a##b:=:c:@experience-v1@",
        "nested": ([ "empty": ([]), "list": ({ }) ])
    ]);
    mapping metadata = ([
        "ratio": 1.25,
        "negative": -2.5,
        "count": -7,
        "values": ({ "", 0, 3.5, "##:=:" })
    ]);
    mapping recorded = dataAccess.recordObservation("gorthaur", ([
        "type": "test.codec.v2",
        "participants": ({ "", "a##b:=:c" }),
        "context": context,
        "metadata": metadata
    ]));
    ExpectTrue(stringp(recorded["ID"]));
    ExpectEq(36, sizeof(recorded["ID"]));
    ExpectFalse(member(recorded, "_observationId"));

    dataAccess.recordObservation("gorthaur", recorded);
    mapping *observations = dataAccess.queryObservationsByPlayer("gorthaur",
        ([ "type": "test.codec.v2" ]));
    ExpectEq(1, sizeof(observations));
    ExpectEq(recorded["ID"], observations[0]["ID"]);
    ExpectEq(context, observations[0]["context"]);
    ExpectEq(metadata, observations[0]["metadata"]);
    ExpectTrue(floatp(observations[0]["metadata"]["ratio"]));
    ExpectTrue(intp(observations[0]["metadata"]["count"]));
    ExpectEq(({ "", "a##b:=:c" }), observations[0]["participants"]);

    int dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, "use " + RealmsDatabase() + ";");
    db_exec(dbHandle, sprintf("select participants, observationContext, "
        "observationMetadata from experienceObservations "
        "where observationKey = '%s';", db_conv_string(recorded["ID"])));
    mixed row = db_fetch(dbHandle);
    ExpectSubStringMatch("@experiences-v2@array:", row[0]);
    ExpectSubStringMatch("@experiences-v2@mapping:", row[1]);
    ExpectSubStringMatch("string:0:", row[1]);
    ExpectSubStringMatch("integer:2:-7", row[2]);
    ExpectSubStringMatch("float:", row[2]);
    while (db_fetch(dbHandle));
    db_close(dbHandle);
    destruct(dataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void PersistedSocialExperienceUnlocksRealResearch()
{
    string research = "/lib/tests/support/research/observant-diplomat.c";
    Player.restore("gorthaur");
    object room = clone_object("/lib/environment/environment.c");
    move_object(Player, room);
    object soul = load_object("/lib/commands/player/soul.c");
    ExpectFalse(Player.canResearch(research));
    ExpectFalse(Player.initiateResearch(research));
    ExpectTrue(soul.execute("smile", Player));
    ExpectTrue(Player.hasObservation(([
        "type": "social.emote",
        "action": "smile"
    ])));
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectTrue(Player.canResearch(research));
    Player.addResearchPoints(1);
    ExpectTrue(Player.initiateResearch(research));
    ExpectTrue(Player.isResearched(research));
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectTrue(Player.isResearched(research));
    destruct(room);
}

/////////////////////////////////////////////////////////////////////////////
private void saveEncodedExperience(string type, string participants,
    string context, string metadata)
{
    int dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, "use " + RealmsDatabase() + ";");
    db_exec(dbHandle, "select id from players where name = 'gorthaur';");
    mixed playerRow = db_fetch(dbHandle);
    while (db_fetch(dbHandle));
    string observationId = generateGuid();
    db_exec(dbHandle, sprintf("call saveExperienceObservation("
        "'%s',%d,'%s','','','%s',777,'','%s','%s');",
        db_conv_string(observationId), to_int(playerRow[0]),
        db_conv_string(type), db_conv_string(participants),
        db_conv_string(context), db_conv_string(metadata)));
    while (db_fetch(dbHandle));
    db_close(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
void ExperiencesLegacyV1CodecRemainsReadable()
{
    string nestedPayload = "1:string:5:countinteger:2:-7";
    string contextPayload = "3:string:5:emptystring:0:"
        "string:4:notestring:8:a##b:=:c" +
        sprintf("string:6:nestedmapping:%d:%s", sizeof(nestedPayload),
            nestedPayload);
    string metadataPayload = "1:string:5:ratiofloat:4:1.25";
    saveEncodedExperience("test.codec.v1",
        "@experience-v1@array:28:2:string:0:string:8:a##b:=:c",
        sprintf("@experience-v1@mapping:%d:%s", sizeof(contextPayload),
            contextPayload),
        sprintf("@experience-v1@mapping:%d:%s", sizeof(metadataPayload),
            metadataPayload));

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    mapping *observations = dataAccess.queryObservationsByPlayer("gorthaur",
        ([ "type": "test.codec.v1" ]));
    ExpectEq(1, sizeof(observations));
    ExpectEq(({ "", "a##b:=:c" }), observations[0]["participants"]);
    ExpectEq(([ "empty": "", "note": "a##b:=:c",
        "nested": ([ "count": -7 ]) ]), observations[0]["context"]);
    ExpectEq(([ "ratio": 1.25 ]), observations[0]["metadata"]);
    ExpectTrue(floatp(observations[0]["metadata"]["ratio"]));
    destruct(dataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void ExperiencesLegacyPlainCodecRemainsReadable()
{
    saveEncodedExperience("test.codec.plain", "first##second",
        "weather:=:snow##count:=:-7", "damage:=:142##note:=:\"old\"");
    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    mapping *observations = dataAccess.queryObservationsByPlayer("gorthaur",
        ([ "type": "test.codec.plain" ]));
    ExpectEq(1, sizeof(observations));
    ExpectEq(({ "first", "second" }), observations[0]["participants"]);
    ExpectEq(([ "weather": "snow", "count": -7 ]),
        observations[0]["context"]);
    ExpectEq(([ "damage": 142, "note": "old" ]),
        observations[0]["metadata"]);
    destruct(dataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void StalePlayerSaveDoesNotDeleteNewObservations()
{
    Player.restore("gorthaur");
    object stalePlayer = clone_object("/lib/realizations/player.c");
    stalePlayer.restore("gorthaur");

    Player.recordObservation(([ "type": "test.append.first" ]));
    Player.save();

    stalePlayer.recordObservation(([ "type": "test.append.second" ]));
    stalePlayer.save();
    stalePlayer.save();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    ExpectEq(1, dataAccess.countObservationsByPlayer("gorthaur",
        ([ "type": "test.append.first" ])));
    ExpectEq(1, dataAccess.countObservationsByPlayer("gorthaur",
        ([ "type": "test.append.second" ])));

    destruct(dataAccess);
    destruct(stalePlayer);
}

/////////////////////////////////////////////////////////////////////////////
void FilteredObservationsPaginationAppliesAfterMatching()
{
    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.recordObservation("gorthaur", ([
        "type": "test.page.match",
        "subject": "first"
    ]));
    dataAccess.recordObservation("gorthaur", ([
        "type": "test.page.skip",
        "subject": "unmatched"
    ]));
    dataAccess.recordObservation("gorthaur", ([
        "type": "test.page.match",
        "subject": "second"
    ]));

    mapping *page = dataAccess.queryObservationsByPlayer("gorthaur",
        ([ "type": "test.page.match" ]), 1, 1);

    ExpectEq(1, sizeof(page));
    ExpectEq("second", page[0]["subject"]);

    destruct(dataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerRelationshipsSaved()
{
    string targetKey = "/lib/realizations/monster#fred";

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");

    dataAccess.updateRelationshipByPlayerAndTarget("gorthaur", targetKey,
        ([ "trust": 3 ]),
        ([ "event": "gift" ]),
        ([ "item": "amulet" ]),
        "relationship.gift");

    ExpectEq(8, dataAccess.relationshipDimensionByPlayerAndTarget("gorthaur",
        targetKey, "trust"));
    ExpectEq(1, sizeof(dataAccess.relationshipHistoryByPlayerAndTarget(
        "gorthaur", targetKey, ([]))));

    destruct(dataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerSkillsSaved()
{
    Player.restore("gorthaur");
    ExpectEq(21, Player.getSkill("long sword"));
    ExpectEq(7, Player.AvailableSkillPoints());
    Player.addSkillPoints(40);
    Player.advanceSkill("long sword", 5);
    Player.save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectEq(26, Player.getSkill("long sword"));
    ExpectEq(42, Player.AvailableSkillPoints());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerTraitsSaved()
{
    Player.restore("gorthaur");
    ExpectEq(({ "/lib/tests/support/traits/testTrait.c", 
        "/lib/tests/support/traits/testTraitWithDuration.c" }),
        Player.Traits());
    Player.addTrait("/lib/instances/traits/personality/abrasive.c");
    Player.save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectEq(({ "/lib/instances/traits/personality/abrasive.c", 
        "/lib/tests/support/traits/testTrait.c", 
        "/lib/tests/support/traits/testTraitWithDuration.c" }),
        Player.Traits());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerInventorySaved()
{
    Player.restore("gorthaur");

    move_object(clone_object("/lib/tests/support/items/testSword.c"), Player);
    Player.addMoney(200000);
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    ExpectFalse(present("Sword of Weasels", Player));
    ExpectEq(0, Player.Money());
    Player.restore("gorthaur");
    ExpectTrue(present("Sword of Weasels", Player)); 
    ExpectEq(212345, Player.Money());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSaveMultiplesOfSameBlueprint()
{
    Player.restore("gorthaur");

    ExpectEq(0, sizeof(all_inventory(Player)));
    move_object(clone_object("/lib/tests/support/items/testSword.c"), Player);
    move_object(clone_object("/lib/tests/support/items/testSword.c"), Player);
    Player.save();
    ExpectEq(2, sizeof(all_inventory(Player)));
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    ExpectEq(0, sizeof(all_inventory(Player)));
    Player.restore("gorthaur");

    object *items = all_inventory(Player);
    ExpectEq(2, sizeof(items));
    ExpectEq("/lib/tests/support/items/testSword.c", items[0]);
    ExpectEq("/lib/tests/support/items/testSword.c", items[1]);
}

/////////////////////////////////////////////////////////////////////////////
void ModifierObjectsAreSavedAndRestored()
{
    Player.restore("gorthaur");
    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus hit points", 6);

    ExpectEq(({}), Player.registeredInventoryObjects());
    ExpectEq(1, modifier.set("registration list", ({ Player })), "registration list can be set");
    ExpectEq(({"/lib/items/modifierObject.c"}), Player.registeredInventoryObjects());
    Player.save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    ExpectEq(({}), Player.registeredInventoryObjects());
    Player.restore("gorthaur");

    ExpectEq(({"/lib/items/modifierObject.c"}), Player.registeredInventoryObjects());
    object item = Player.registeredInventoryObject("blah");
    ExpectTrue(item);
    ExpectEq(6, item.query("bonus hit points"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerInventoryMaintainsWieldedAndWornStateWhenEquippedAtSave()
{
    getService("environment");

    ToggleCallOutBypass();
    Player.restore("gorthaur");

    object weapon = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    weapon.set("name", "Sword of Weasels");
    move_object(weapon, Player);
    ExpectTrue(weapon.equip("Sword of Weasels"), "sword equip succeeded");
    ExpectTrue(Player.isEquipped(weapon), "sword equipped");

    object shield = clone_object("/lib/items/weapon");
    shield.set("name", "Shield of Weasels");
    shield.set("defense class", 1);
    shield.set("material", "steel");
    shield.set("craftsmanship", 20);
    shield.set("weapon type", "shield");
    move_object(shield, Player);
    ExpectTrue(shield.equip("Shield of Weasels"), "shield equip succeeded");
    ExpectTrue(Player.isEquipped(shield), "shield equipped");

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "Armor of Weasels");
    armor.set("bonus hit points", 4);
    armor.set("armor class", 5);
    armor.set("armor type", "chainmail");
    move_object(armor, Player);
    ExpectTrue(armor.equip("Armor of Weasels"), "armor equip succeeded");
    ExpectTrue(Player.isEquipped(armor), "armor equipped");

    Player.save();

    destruct(armor);
    destruct(weapon);
    destruct(shield);
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    ExpectFalse(present("Sword of Weasels", Player), "sword not present after re-clone");
    Player.restore("gorthaur");
    ExpectTrue(present("Sword of Weasels", Player), "sword equip after re-clone");
    ExpectEq("/lib/instances/items/weapons/swords/long-sword.c",
        Player.equipmentInSlot("wielded primary"), "sword wielded after re-clone");

    shield = Player.equipmentInSlot("wielded offhand");
    ExpectEq("/lib/items/weapon.c", shield, "shield still in slot");
    // It's also important that the "generic" items maintain set data!
    ExpectEq("Shield of Weasels", shield.query("name"));

    armor = Player.equipmentInSlot("armor");
    ExpectEq("/lib/items/armor.c", armor, "armor still in slot");
    // It's also important that the "generic" items maintain set data!
    ExpectEq("Armor of Weasels", armor.query("name"));
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void PlayerFactionsSaved()
{
    Player.restore("gorthaur");
    ExpectTrue(Player.memberOfFaction("/lib/tests/support/factions/badGuys.c"));
    Player.leaveFaction("/lib/tests/support/factions/badGuys.c");
    Player.save();
    destruct(Player);

    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectFalse(Player.memberOfFaction("/lib/tests/support/factions/badGuys.c"));
    ExpectEq("betrayed", Player.factionDispositionToward("/lib/tests/support/factions/badGuys.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CombatStatisticsCorrectlyApplied()
{
    Player.restore("gorthaur");

    object foe = clone_object("/lib/realizations/monster.c");
    foe.Name("Rargh!");
    foe.Race("orc");
    foe.effectiveLevel(8);

    Player.saveCombatStatistics(Player, foe);

    ExpectTrue(Player.bestKillMeetsLevel(8));
    ExpectTrue(Player.racialKillsMeetCount("orc", 1));
}

/////////////////////////////////////////////////////////////////////////////
void GetBestKillReturnsBestKill()
{
    Player.restore("gorthaur");

    object foe = clone_object("/lib/realizations/monster.c");
    foe.Name("blarg");
    foe.Race("orc");
    foe.effectiveLevel(18);

    Player.saveCombatStatistics(Player, foe);

    ExpectEq((["name": "Blarg",
               "level" : 18,
               "key" : "/lib/realizations/monster.c#Blarg",
               "times killed" : 1]),
        Player.getBestKill("gorthaur"));
}

/////////////////////////////////////////////////////////////////////////////
void GetNemesisReturnsNemesis()
{
    Player.restore("gorthaur");

    object foe = clone_object("/lib/realizations/monster.c");
    foe.Name("Rargh!");
    foe.Race("orc");
    foe.effectiveLevel(8);

    Player.saveCombatStatistics(Player, foe);

    ExpectEq((["name": "Rargh!",
               "level" : 8,
               "key" : "/lib/realizations/monster.c#Rargh!",
               "times killed" : 2]),
        Player.getNemesis("gorthaur"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerTypeReturnsForWizard()
{
    object wizard = clone_object("/lib/realizations/wizard.c");
    wizard.restore("earl");
    ExpectEq(({ "admin", "apprentice", "creator", "elder", "highwizard", "player", "senior", "wizard" }),
        wizard.groups());
    destruct(wizard);
}

/////////////////////////////////////////////////////////////////////////////
void OpinionOfCharacterReturnsCorrectValue()
{
    Player.restore("gorthaur");
    object foe = clone_object("/lib/realizations/monster.c");
    foe.Name("Betty");

    ExpectEq(0, Player.opinionOfCharacter(foe));
    ExpectEq(5, Player.opinionOfCharacter(foe, 5));
    ExpectEq(11, Player.opinionOfCharacter(foe, 6));
    ExpectEq(11, Player.opinionOfCharacter(foe));
}

/////////////////////////////////////////////////////////////////////////////
void CharacterStateReturnsCorrectValue()
{
    Player.restore("gorthaur");
    object foe = clone_object("/lib/realizations/monster.c");
    foe.Name("Betty");

    ExpectEq(0, Player.characterState(foe));
    ExpectEq("some state", Player.characterState(foe, "some state"));
    ExpectEq("new state", Player.characterState(foe, "new state"));
    ExpectEq("new state", Player.characterState(foe));
}

/////////////////////////////////////////////////////////////////////////////
void HeartBeatChecksForLinkDeathThenSavesAndDestroysTheLinkDead()
{
    ToggleInteractive();
    Player.restore("gorthaur");
    setUsers(({ Player }));
    Player.heart_beat();

    ExpectTrue(Player);
    ExpectEq(StartLocation(), Player.savedLocation());

    move_object(Player, "/lib/tests/support/environment/startingRoom.c");
    setUsers(({ }));

    Player.heart_beat();
    ExpectFalse(Player);

    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");

    ExpectEq("/lib/tests/support/environment/startingRoom", Player.savedLocation());
    ToggleInteractive();
}

/////////////////////////////////////////////////////////////////////////////
void PlayerSettingsSaved()
{
    Player.restore("gorthaur");
    Player.setBusy("on");
    Player.setEarmuffs("on");
    Player.pageSize(35);
    Player.colorConfiguration("24-bit");
    Player.charsetConfiguration("unicode");
    Player.combatVerbosity("digest");
    Player.save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");

    ExpectTrue(Player.isBusy());
    ExpectTrue(Player.isEarmuffed());
    ExpectEq(35, Player.pageSize());
    ExpectEq("24-bit", Player.colorConfiguration());
    ExpectEq("unicode", Player.charsetConfiguration());
    ExpectEq("digest", Player.combatVerbosity());
    ExpectEq(5, Player.attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerBlockSettingsSaved()
{
    Player.restore("gorthaur");
    Player.block("gorthaur");
    Player.save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectTrue(Player.blocked(Player));

    Player.unblock("gorthaur");
    Player.save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectFalse(Player.blocked(Player));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerRemoveGuildRemovesPersistedData()
{
    object blarg = load_object("/lib/tests/support/guilds/blargGuild.c");

    Player.restore("gorthaur");
    ExpectTrue(Player.memberOfGuild("blarg"), "Is member of blarg");
    ExpectTrue(Player.isResearched("/lib/tests/support/research/testGrantedResearchItem.c"), "granted research is researched");
    ExpectTrue(Player.isResearched("/lib/tests/support/research/compositeResearchItemA.c"), "A research is researched");
    ExpectTrue(Player.isResearched("/lib/tests/support/research/compositeResearchItemB.c"), "B research is researched");
    ExpectTrue(Player.isResearched("/lib/tests/support/research/compositeResearchItemC.c"), "C research is researched");
    ExpectTrue(Player.isResearched("/lib/tests/support/research/compositeRoot.c"), "compositeRoot research is researched");
    ExpectTrue(Player.isResearched("/lib/tests/support/research/testSustainedResearchItem.c"), "sustained research is researched");
    ExpectEq(({ "/lib/tests/support/research/testSecondResearchTree.c", 
        "/lib/tests/support/research/testBlargTree.c",
        "/lib/tests/support/research/testConstructedTree.c" }),
        Player.availableResearchTrees());
    ExpectTrue(member(Player.getCompositeResearch("/lib/tests/support/research/compositeRoot.c"), "Song of the Weasels"), "Composite present");

    ExpectTrue(Player.isResearched("/lib/tests/support/research/constructedRoot.c"), "constructedRoot research is researched");
    ExpectTrue(Player.isResearched("/lib/tests/support/research/constructedFormA.c"), "constructedFormA research is researched");
    ExpectTrue(Player.isResearched("/lib/tests/support/research/constructedFunctionA.c"), "constructedFunctionA research is researched");
    ExpectTrue(Player.isResearched("/lib/tests/support/research/constructedEffectA.c"), "constructedEffectA research is researched");
    ExpectTrue(member(Player.getConstructedResearch("/lib/tests/support/research/constructedRoot.c"), "Bolt of Doom"), "Bolt of Doom present");

    Player.removeGuild("blarg");

    ExpectFalse(Player.memberOfGuild("blarg"), "Is not member of blarg");
    ExpectTrue(Player.isResearched("/lib/tests/support/research/testGrantedResearchItem.c"), "granted research is researched");
    ExpectFalse(Player.isResearched("/lib/tests/support/research/compositeResearchItemA.c"), "A research is not researched");
    ExpectFalse(Player.isResearched("/lib/tests/support/research/compositeResearchItemB.c"), "B research is not researched");
    ExpectFalse(Player.isResearched("/lib/tests/support/research/compositeResearchItemC.c"), "C research is not researched");
    ExpectFalse(Player.isResearched("/lib/tests/support/research/compositeRoot.c"), "compositeRoot research is not researched");
    ExpectTrue(Player.isResearched("/lib/tests/support/research/testSustainedResearchItem.c"), "sustained research is researched");
    ExpectEq(({ "/lib/tests/support/research/testSecondResearchTree.c" }),
        Player.availableResearchTrees());
    ExpectFalse(member(Player.getCompositeResearch("/lib/tests/support/research/compositeRoot.c"), "Song of the Weasels"), "Composite present");

    ExpectFalse(Player.isResearched("/lib/tests/support/research/constructedRoot.c"), "constructedRoot research is not researched");
    ExpectFalse(Player.isResearched("/lib/tests/support/research/constructedFormA.c"), "constructedFormA research is not researched");
    ExpectFalse(Player.isResearched("/lib/tests/support/research/constructedFunctionA.c"), "constructedFunctionA research is not researched");
    ExpectFalse(Player.isResearched("/lib/tests/support/research/constructedEffectA.c"), "constructedEffectA research is not researched");
    ExpectFalse(member(Player.getConstructedResearch("/lib/tests/support/research/constructedRoot.c"), "Bolt of Doom"), "Bolt of Doom not present");

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectFalse(Player.memberOfGuild("blarg"), "Is not member of blarg");
    ExpectTrue(Player.isResearched("/lib/tests/support/research/testGrantedResearchItem.c"), "granted research is researched");
    ExpectFalse(Player.isResearched("/lib/tests/support/research/compositeResearchItemA.c"), "A research is not researched");
    ExpectFalse(Player.isResearched("/lib/tests/support/research/compositeResearchItemB.c"), "B research is not researched");
    ExpectFalse(Player.isResearched("/lib/tests/support/research/compositeResearchItemC.c"), "C research is not researched");
    ExpectFalse(Player.isResearched("/lib/tests/support/research/compositeRoot.c"), "compositeRoot research is not researched");
    ExpectTrue(Player.isResearched("/lib/tests/support/research/testSustainedResearchItem.c"), "sustained research is researched");
    ExpectEq(({ "/lib/tests/support/research/testSecondResearchTree.c" }),
        Player.availableResearchTrees());

    ExpectFalse(member(Player.getCompositeResearch("/lib/tests/support/research/compositeRoot.c"), "Song of the Weasels"));

    ExpectFalse(Player.memberOfGuild("blarg"), "Is not member of blarg after restore");
    ExpectFalse(Player.isResearched("/lib/tests/support/research/constructedRoot.c"), "constructedRoot research is not researched after restore");
    ExpectFalse(Player.isResearched("/lib/tests/support/research/constructedFormA.c"), "constructedFormA research is not researched after restore");
    ExpectFalse(Player.isResearched("/lib/tests/support/research/constructedFunctionA.c"), "constructedFunctionA research is not researched after restore");
    ExpectFalse(Player.isResearched("/lib/tests/support/research/constructedEffectA.c"), "constructedEffectA research is not researched after restore");
    ExpectFalse(member(Player.getConstructedResearch("/lib/tests/support/research/constructedRoot.c"), "Bolt of Doom"), "Bolt of Doom not present after restore");
}
