//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

private object Database;
private object DataAccess;
private object Player;

void Init()
{
    ignoreList += ({ "sqlRows" });
}

private mixed *sqlRows(string query)
{
    mixed *ret = ({ });
    if (RealmsDatabase() != "RealmsQA")
    {
        raise_error("Observation persistence tests require QA.\n");
    }
    else
    {
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
    }
    return ret;
}

void Setup()
{
    setRestoreCaller(this_object());
    Database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    Database.PrepDatabase();
    object authentication = clone_object(
        "/lib/modules/secure/dataServices/authenticationDataService.c");
    authentication.saveUser("gorthaur", "gorthaur", "127.0.0.1");
    destruct(authentication);
    DataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    DataAccess.savePlayerData(Database.Gorthaur());
    Player = clone_object("/lib/realizations/player.c");
}

void CleanUp()
{
    sqlRows("drop trigger if exists observationTestFailure;");
    destruct(Player);
    destruct(DataAccess);
    destruct(Database);
}

void BoundedRestoreQueriesLifetimeAndPendingWithoutDoubleCounting()
{
    DataAccess.recordObservation("gorthaur", ([
        "ID": "old-social", "type": "social.emote",
        "context": ([ "action": "smile" ])
    ]));
    for (int index = 0; index < 105; index++)
    {
        DataAccess.recordObservation("gorthaur", ([
            "ID": sprintf("history-%d", index), "type": "history.event",
            "context": ([ "sequence": index ])
        ]));
    }
    Player.restore("gorthaur");
    ExpectEq(100, sizeof(Player.experiencesLog()));
    ExpectEq(105, Player.countObservations(([ "type": "history" ])));
    ExpectTrue(Player.hasObservation(([ "ID": "history-0" ])));
    ExpectTrue(Player.canResearch(
        "/lib/tests/support/research/observant-diplomat.c"));
    Player.recordObservation(([ "ID": "pending", "type": "history.event" ]));
    Player.recordObservation(([ "ID": "pending", "type": "history.event" ]));
    DataAccess.recordObservation("gorthaur", ([
        "ID": "pending", "type": "history.event"
    ]));
    Player.recordObservation(([ "ID": "pending-2", "type": "history.event" ]));
    ExpectEq(107, Player.countObservations(([ "type": "history" ])));
    mapping *page = Player.queryObservations(([ "type": "history" ]), 2, 104);
    ExpectEq(2, sizeof(page));
    ExpectEq("history-104", page[0]["ID"]);
    ExpectEq("pending", page[1]["ID"]);
    page = Player.queryObservations(([ "type": "history" ]), 1, 106);
    ExpectEq("pending-2", page[0]["ID"]);
    ExpectEq(0, sizeof(Player.queryObservations(
        ([ "type": "history" ]), 1, 107)));
    Player.save();
    ExpectEq(100, sizeof(Player.experiencesLog()));
    ExpectEq(107, Player.countObservations(([ "type": "history" ])));
}

void SavesOnlyPendingRowsAndAcknowledgesSuccessfulBatch()
{
    Player.restore("gorthaur");
    sqlRows("create trigger observationTestFailure before insert on "
        "experienceObservations for each row begin "
        "if exists(select 1 from experienceObservations where "
        "observationKey=NEW.observationKey) then signal sqlstate '45000' "
        "set message_text='Historical observation resent'; end if; end;");
    Player.recordObservation(([ "ID": "delta", "type": "delta.event" ]));
    mixed firstFailure = catch(Player.save(); nolog);
    mixed secondFailure = catch(Player.save(); nolog);
    sqlRows("drop trigger observationTestFailure;");
    ExpectFalse(firstFailure);
    ExpectFalse(secondFailure);
    ExpectEq(1, DataAccess.countObservationsByPlayer("gorthaur",
        ([ "type": "delta" ])));
}

void FailedBatchRollsBackAndPendingRowsRetry()
{
    Player.restore("gorthaur");
    Player.recordObservation(([ "ID": "retry-first", "type": "retry.event" ]));
    Player.recordObservation(([ "ID": "retry-failure", "type": "retry.event" ]));
    sqlRows("create trigger observationTestFailure before insert on "
        "experienceObservations for each row begin "
        "if NEW.observationKey='retry-failure' then signal sqlstate '45000' "
        "set message_text='Injected observation save failure'; end if; end;");
    mixed failure = catch(Player.save(); nolog);
    sqlRows("drop trigger observationTestFailure;");
    ExpectTrue(stringp(failure));
    ExpectEq(0, DataAccess.countObservationsByPlayer("gorthaur",
        ([ "type": "retry" ])));
    ExpectEq(2, Player.countObservations(([ "type": "retry" ])));
    Player.save();
    ExpectEq(2, DataAccess.countObservationsByPlayer("gorthaur",
        ([ "type": "retry" ])));
    ExpectEq(2, Player.countObservations(([ "type": "retry" ])));
    Player.save();
    ExpectEq(2, DataAccess.countObservationsByPlayer("gorthaur",
        ([ "type": "retry" ])));
}