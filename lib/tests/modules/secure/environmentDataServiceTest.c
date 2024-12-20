//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object DataAccess;
object Database;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    Database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    Database.PrepDatabase();
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    DataAccess = 
        clone_object("/lib/modules/secure/dataServices/environmentDataService.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(DataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void CanLoadDataFromDatabase()
{
    ExpectEq(([ 
        "day": 92, 
        "time": 660,
        "year": 2942 ]), 
        DataAccess.loadEnvironmentData());
}

/////////////////////////////////////////////////////////////////////////////
void CanSaveToDatabase()
{
    DataAccess.saveEnvironmentData(1022, 194, 1991);

    ExpectEq(([
        "day": 194, 
        "time": 1022,
        "year": 1991 ]), 
        DataAccess.loadEnvironmentData());
}
