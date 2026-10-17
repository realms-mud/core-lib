//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/experiences.c";

private int testObservationPlayerId;

/////////////////////////////////////////////////////////////////////////////
public int observationTestPlayerId()
{
    return testObservationPlayerId;
}

/////////////////////////////////////////////////////////////////////////////
protected int experienceOwnerId()
{
    return testObservationPlayerId ? testObservationPlayerId :
        experiences::experienceOwnerId();
}

/////////////////////////////////////////////////////////////////////////////
public void enableObservationPersistence()
{
    if (RealmsDatabase() != "RealmsQA")
    {
        raise_error("Observation fixtures require the QA database.\n");
    }
    if (!testObservationPlayerId)
    {
        int handle = db_connect(RealmsDatabase());
        string name = "observation-" +
            explode(object_name(this_object()), "#")[<1];
        db_exec(handle, sprintf("insert into players (name) values ('%s');",
            db_conv_string(name)));
        if (db_error(handle))
        {
            raise_error("Observation fixture setup failed: " +
                db_error(handle) + "\n");
        }
        while (db_fetch(handle));
        db_exec(handle, "select LAST_INSERT_ID();");
        mixed row = db_fetch(handle);
        testObservationPlayerId = to_int(row[0]);
        while (db_fetch(handle));
        db_close(handle);
    }
}

/////////////////////////////////////////////////////////////////////////////
public void disableObservationPersistence()
{
    if (testObservationPlayerId)
    {
        int handle = db_connect(RealmsDatabase());
        string name = "observation-" +
            explode(object_name(this_object()), "#")[<1];
        foreach(string table in ({ "experienceObservations", "players" }))
        {
            string predicate = table == "players" ?
                sprintf("id=%d and name='%s'", testObservationPlayerId,
                    db_conv_string(name)) :
                sprintf("playerId in (select id from players where "
                    "id=%d and name='%s')", testObservationPlayerId,
                    db_conv_string(name));
            db_exec(handle, sprintf("delete from %s where %s;",
                table, predicate));
            if (db_error(handle))
            {
                raise_error("Observation fixture cleanup failed: " +
                    db_error(handle) + "\n");
            }
            while (db_fetch(handle));
        }
        db_close(handle);
        testObservationPlayerId = 0;
    }
}
