//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Npc;
object Database;
object DataAccess;

void Setup()
{
    setRestoreCaller(this_object());
    Database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    validateTestDatabase();
    object authentication = clone_object(
        "/lib/modules/secure/dataServices/authenticationDataService.c");
    authentication.saveUser("gorthaur", "gorthaur", "127.0.0.1");
    destruct(authentication);
    DataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    DataAccess.savePlayerData(Database.Gorthaur());
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    Npc = clone_object("/lib/tests/support/relationships/npc.c");
}

void CleanUp()
{
    if (objectp(Npc))
    {
        destruct(Npc);
    }
    if (objectp(Player))
    {
        destruct(Player);
    }
    if (objectp(DataAccess))
    {
        destruct(DataAccess);
    }
    if (objectp(Database))
    {
        destruct(Database);
    }
}

void BothDirectionsAndMultipleTargetsSurviveSaveDestroyRestore()
{
    string npcKey = getService("relationship")->identity(Npc);
    Player.modifyRelationship(Npc, "trust", 12);
    Player.modifyRelationship("/actors/second.c#Second", "respect", 7);
    Npc.modifyRelationship(Player, "trust", 34);
    Player.updateRelationshipFrom("/actors/third.c#Third", ([ "fear":8 ]));
    Player.recordRelationshipInteraction(Npc, "gift.given",
        ([ "gratitude":5 ]), ([ "item":"amulet" ]));
    Player.save();
    Player.save();
    destruct(Player);
    destruct(Npc);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    Npc = clone_object("/lib/tests/support/relationships/npc.c");
    ExpectEq(12, Player.relationshipValue(npcKey, "trust"));
    ExpectEq(34, Npc.relationshipValue(Player, "trust"));
    ExpectEq(7, Player.relationshipValue("/actors/second.c#Second", "respect"));
    ExpectEq(3, sizeof(DataAccess.queryRelationshipsByPlayer(
        "gorthaur", ([]))));
    ExpectEq(8, Player.relationshipFrom("/actors/third.c#Third")[
        "dimensions"]["fear"]);
    ExpectEq(1, Player.countObservations(([ "type":"gift.given" ])));
    Npc.modifyRelationship(Player, "trust", 1);
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectEq(35, Npc.relationshipValue(Player, "trust"));
}

void LegacyHistoryIsPreservedWithoutCreatingNewHistory()
{
    string target = "/lib/realizations/monster#fred";
    ExpectEq(1, sizeof(Player.relationshipHistoryToward(target, ([]))));
    Player.modifyRelationship(target, "trust", 3);
    Player.save();
    Player.save();
    ExpectEq(1, sizeof(DataAccess.relationshipHistoryByPlayerAndTarget(
        "gorthaur", target, ([]))));
}

void NpcRelationshipsPersistAndRefreshAcrossIndependentClones()
{
    object other = clone_object("/lib/tests/support/relationships/npc.c");
    other.Name("bob");
    Npc.updateRelationshipToward(other, ([
        "trust":60, "respect":50, "affection":40
    ]));
    ExpectEq("friend", Npc.relationshipType(other));
    ExpectEq(16, Npc.relationshipSummary(other)["strength"]);
    mapping snapshot = Npc.relationshipSummary(other);
    snapshot["classification"] = "enemy";
    ExpectEq("friend", Npc.relationshipSummary(other)["classification"]);
    object second = clone_object("/lib/tests/support/relationships/npc.c");
    second.modifyRelationship(other, "trust", -100);
    ExpectEq(-40, Npc.relationshipValue(other, "trust"));
    ExpectEq("acquaintance", Npc.relationshipType(other));
    ExpectEq(0, other.relationshipValue(Npc, "trust"));
    ExpectEq(1, sizeof(Npc.queryRelationships(([ "trust":-40 ]))));
    destruct(Npc);
    Npc = clone_object("/lib/tests/support/relationships/npc.c");
    ExpectEq(-40, Npc.relationshipValue(other, "trust"));
    ExpectEq(14, Npc.relationshipSummary(other)["strength"]);
    destruct(second);
    destruct(other);
}

void TimedMentorshipSurvivesTeacherAndStudentDestruction()
{
    string item = "/lib/tests/support/research/testTimedResearchItem.c";
    ExpectTrue(Npc.initiateResearch(item));
    for (int step = 0; step < 5; step++)
    {
        Npc.heart_beat();
    }

    ExpectTrue(Npc.isResearched(item));
    ExpectTrue(Player.learnResearchFrom(Npc, item));
    string teacher = Npc.relationshipIdentity();
    Player.heart_beat();
    Player.heart_beat();
    ExpectEq(0, Player.countObservations(([ "type":"training.completed" ])));
    Player.save();
    destruct(Npc);
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    Player.heart_beat();
    Player.heart_beat();
    ExpectFalse(Player.isResearched(item));
    Player.heart_beat();
    ExpectTrue(Player.isResearched(item));
    ExpectEq(1, Player.countObservations(([ "type":"training.completed" ])));
    ExpectEq(2, Player.relationshipFrom(teacher)["dimensions"]["respect"]);
    Player.heart_beat();
    Player.save();
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    Player.heart_beat();
    ExpectEq(1, Player.countObservations(([ "type":"training.completed" ])));
    ExpectEq(2, Player.relationshipFrom(teacher)["dimensions"]["respect"]);
}

void NpcCacheRefreshesAcrossPlayerRestore()
{
    Npc.updateRelationshipToward(Player,
        ([ "trust":60, "respect":50, "affection":40 ]));
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectEq("friend", Npc.relationshipType(Player));
    Npc.modifyRelationship(Player, "trust", -100);
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectEq("acquaintance", Npc.relationshipType(Player));
    ExpectEq(-40, Npc.relationshipValue(Player, "trust"));
}

void WorldChangesRejectInvalidBatchesAndOfflinePlayerEndpoints()
{
    object other = clone_object("/lib/tests/support/relationships/npc.c");
    other.Name("bob");
    ExpectTrue(stringp(catch(Npc.updateRelationshipToward(other,
        ([ "trust":10, "invalid dimension":2 ])); nolog)));
    ExpectFalse(Npc.hasRelationship(other));
    Npc.updateRelationshipToward(other,
        ([ "trust":1000, "suspicion":-1000 ]));
    ExpectEq(100, Npc.relationshipValue(other, "trust"));
    ExpectEq(0, Npc.relationshipValue(other, "suspicion"));
    string playerKey = Player.relationshipIdentity();
    ExpectTrue(stringp(catch(Npc.modifyRelationship(playerKey,
        "trust", 10); nolog)));
    ExpectTrue(stringp(catch(Npc.relationshipToward(playerKey); nolog)));
    ExpectEq(0, Npc.relationshipValue(Player, "trust"));
    destruct(other);
}

void FailedMentorshipSaveRollsBackPruningThePendingLesson()
{
    string item = "/lib/tests/support/research/testTimedResearchItem.c";
    Npc.initiateResearch(item);
    for (int step = 0; step < 5; step++)
    {
        Npc.heart_beat();
    }
    ExpectTrue(Player.learnResearchFrom(Npc, item));
    Player.heart_beat();
    Player.heart_beat();
    Player.save();
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    mapping badSave = database.Gorthaur();
    badSave["researchMentorships"] = ([
        "invalid lesson":([ "teacher":([]), "changes":([ "respect":2 ]) ])
    ]);
    ExpectTrue(stringp(catch(load_object("/lib/modules/secure/dataAccess.c")
        ->savePlayerData(badSave); nolog)));
    destruct(database);
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    Player.heart_beat();
    Player.heart_beat();
    Player.heart_beat();
    ExpectTrue(Player.isResearched(item));
    ExpectEq(1, Player.countObservations(([ "type":"training.completed" ])));
    ExpectEq(2, Npc.relationshipValue(Player, "respect"));
}

void BetrayalEvidenceAndNpcAttitudeSurviveDestruction()
{
    object room = clone_object("/lib/tests/support/relationships/room.c");
    Npc.Con(20);
    Npc.Race("human");
    Npc.maxHitPoints(1000);
    Npc.hitPoints(1000);
    move_object(Npc, room);
    move_object(Player, room);
    Npc.updateRelationshipToward(Player,
        ([ "trust":60, "respect":50, "affection":40 ]));
    ExpectTrue(Player.attack(Npc));
    Player.save();
    destruct(Npc);
    destruct(Player);
    destruct(room);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    Npc = clone_object("/lib/tests/support/relationships/npc.c");
    ExpectEq(30, Npc.relationshipValue(Player, "trust"));
    ExpectEq(35, Npc.relationshipValue(Player, "respect"));
    ExpectEq(1, Player.countObservations(([ "type":"combat.betrayal" ])));
}
