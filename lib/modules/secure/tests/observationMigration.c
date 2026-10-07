//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/simulated-efuns/database.c";

public void replayObservationMigration()
{
    if (RealmsDatabase() != "RealmsQA" ||
        program_name(previous_object()) !=
            "/lib/tests/modules/secure/observationDatabaseTest.c")
    {
        raise_error("Observation migration replay is restricted to QA.\n");
    }
    else
    {
        int handle = efun::db_connect(RealmsDatabase());
        migrateDatabase(handle, 12, 13);
        db_close(handle);
    }
}