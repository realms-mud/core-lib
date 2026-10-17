//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

private object Database;
private object DataAccess;
private object Player;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "sqlRows" });
    setRestoreCaller(this_object());
    Database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    Database.PrepDatabase();
    object authentication = clone_object(
        "/lib/modules/secure/dataServices/authenticationDataService.c");
    authentication.saveUser("gorthaur", "gorthaur", "127.0.0.1");
    destruct(authentication);
    DataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    DataAccess.savePlayerData(Database.Gorthaur());
}

/////////////////////////////////////////////////////////////////////////////
private mixed *sqlRows(string query)
{
    mixed *ret = ({ });
    int handle = db_connect(RealmsDatabase());
    db_exec(handle, query);
    string failure = db_error(handle);
    mixed row;
    while (row = db_fetch(handle))
    {
        ret += ({ row });
    }
    db_close(handle);
    if (failure)
    {
        raise_error(failure + "\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    sqlRows("delete from experienceObservations;");
    DataAccess.recordObservation("gorthaur",
        Database.Gorthaur()["experiences"][0]);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    sqlRows("drop trigger if exists observationTestFailure;");
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void TearDown()
{
    destruct(DataAccess);
    destruct(Database);
}

/////////////////////////////////////////////////////////////////////////////
void RecordingIsImmediatelyVisibleAcrossPlayerInstances()
{
    object other = clone_object("/lib/realizations/player.c");
    other.restore("gorthaur");
    Player.recordObservation(([ "type":"immediate.event" ]));
    ExpectEq(1, other.countObservations(([ "type":"immediate" ])));
    ExpectEq(1, DataAccess.countObservationsByPlayer("gorthaur",
        ([ "type":"immediate" ])));
    other.save();
    Player.save();
    Player.restore("gorthaur");
    ExpectEq(1, Player.countObservations(([ "type":"immediate" ])));
    ExpectFalse(function_exists("experiencesLog", Player));
    ExpectFalse(function_exists("experiencesSummary", Player));
    ExpectFalse(member(DataAccess.getPlayerData("gorthaur"), "experiences"));
    destruct(other);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerSaveNeverResubmitsObservationHistory()
{
    Player.recordObservation(([ "type":"saved.event" ]));
    sqlRows("create trigger observationTestFailure before insert on "
        "experienceObservations for each row signal sqlstate '45000' "
        "set message_text='Player save must not insert observations';");
    mixed failure = catch(Player.save(); nolog);
    ExpectFalse(failure);
    ExpectEq(1, Player.countObservations(([ "type":"saved" ])));
}

/////////////////////////////////////////////////////////////////////////////
void IdenticalEventsReceiveDistinctDatabasePrimaryKeys()
{
    mapping observation = ([ "type":"identical.event", "timestamp":1234 ]);
    Player.recordObservation(observation);
    Player.recordObservation(observation);
    mapping *saved = Player.queryObservations(([ "type":"identical" ]));
    ExpectEq(2, sizeof(saved));
    ExpectTrue(to_int(saved[0]["ID"]) > 0);
    ExpectTrue(to_int(saved[1]["ID"]) > 0);
    ExpectTrue(saved[0]["ID"] != saved[1]["ID"]);
    Player.save();
    ExpectEq(2, Player.countObservations(([ "type":"identical" ])));
}

/////////////////////////////////////////////////////////////////////////////
void FailedRecordingIsReportedAndDoesNotCreatePendingHistory()
{
    sqlRows("create trigger observationTestFailure before insert on "
        "experienceObservations for each row signal sqlstate '45000' "
        "set message_text='Injected observation write failure';");
    mixed failure = catch(Player.recordObservation(([
        "type":"failure.event"
    ])); nolog);
    ExpectTrue(stringp(failure));
    sqlRows("drop trigger observationTestFailure;");
    ExpectFalse(Player.hasObservation(([ "type":"failure" ])));
    Player.save();
    ExpectFalse(Player.hasObservation(([ "type":"failure" ])));
    Player.recordObservation(([ "type":"failure.event" ]));
    ExpectEq(1, Player.countObservations(([ "type":"failure" ])));
}

/////////////////////////////////////////////////////////////////////////////
void NpcInteractionsAreOwnedAndQueriedByTheTriggeringPlayer()
{
    object npc = clone_object("/lib/realizations/monster.c");
    npc.Name("Chen");
    Player.recordObservation(([
        "type":"conversation.helped",
        "subject":npc,
        "participants":({ npc })
    ]));
    ExpectTrue(Player.hasObservation(([
        "type":"conversation",
        "subject":npc,
        "participants":({ npc })
    ])));
    ExpectFalse(npc.recordsObservations());
    ExpectFalse(npc.recordObservation(([ "type":"npc.private" ])));
    ExpectEq(0, npc.countObservations(([])));
    mapping another = Database.Gorthaur();
    another["name"] = "another";
    another["experiences"] = ({ });
    DataAccess.savePlayerData(another);
    ExpectFalse(DataAccess.hasObservationByPlayer("another", ([
        "subject":npc
    ])));
    destruct(npc);
}

/////////////////////////////////////////////////////////////////////////////
void RestoreKeepsDatabaseHistoryWithoutHydratingIt()
{
    sqlRows("delete from experienceObservations;");
    mapping data = Database.Gorthaur();
    data["experiences"] += ({ ([
        "type":"combat.kata.tiger",
        "actor":"/lib/realizations/player#gorthaur",
        "subject":"orc",
        "participants":({ }),
        "timestamp":100,
        "location":"temple",
        "context":([ "minutes after midnight":1380, "weapon":"katana" ]),
        "metadata":([ "outcome":"success" ])
    ]) });
    DataAccess.savePlayerData(data);
    object player = clone_object("/lib/realizations/player.c");
    ExpectFalse(player.recordObservation(([ "type":"movement.enter" ])));
    player.restore("gorthaur");
    ExpectEq(0, player.countObservations(([ "type":"movement" ])));
    ExpectEq(2, player.countObservations(([ "type":"combat" ])));
    mapping criteria = ([
        "type":"combat.kata",
        "time window":([ "center":0, "minutes":60 ]),
        "since":100,
        "until":100,
        "weapon":"KATANA",
        "outcome":"success"
    ]);
    ExpectEq(1, player.countObservations(criteria));
    ExpectEq(player.queryObservations(criteria),
        DataAccess.queryObservationsByPlayer("gorthaur", criteria, 0, 0));
    criteria["time window"]["minutes"] = "invalid";
    ExpectEq(0, player.countObservations(criteria));
    ExpectEq(0, DataAccess.countObservationsByPlayer("gorthaur", criteria));
    ExpectEq(0, DataAccess.countObservationsByPlayer("gorthaur", 0));
    player.recordObservation(([ "type":"research.learn" ]));
    player.restore("gorthaur");
    ExpectEq(1, player.countObservations(([ "type":"research" ])));
    ExpectEq(2, player.countObservations(([ "type":"combat" ])));
    destruct(player);
}
