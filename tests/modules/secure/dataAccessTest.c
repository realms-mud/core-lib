//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    Database->PrepDatabase();
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    DataAccess = clone_object("/lib/modules/secure/dataAccess.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(DataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerTypeReturnsCorrectWizardValueFromDatabase()
{
    ExpectEq("owner", DataAccess->playerType("maeglin"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerTypeReturnsPlayerWhenNotWizard()
{
    ExpectEq("player", DataAccess->playerType("gorthaur"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerTypeReturnsPlayerWhenNotInDatabase()
{
    ExpectEq("player", DataAccess->playerType("fake player"));
}

/////////////////////////////////////////////////////////////////////////////
void GetPlayerDataReturnsDataFromDatabase()
{
    mapping expected = Database->Gorthaur();

    DataAccess->savePlayerData(expected);
    mapping result = DataAccess->getPlayerData("gorthaur");

    // whenCreated uses "now()" and it's not feasible (without adding a test-only hack)
    // to add a static, testable value. For now, simply test its existance and
    // remove it before testing the rest of the mapping.
    ExpectTrue(member(result, "whenCreated"));
    m_delete(result, "whenCreated");

    ExpectEq(expected, result);
}

/////////////////////////////////////////////////////////////////////////////
void CanSaveDataMultipleTimes()
{
    DataAccess->savePlayerData(Database->Gorthaur());
    mapping result = DataAccess->getPlayerData("gorthaur");
    ExpectEq(100, result["hitPoints"]);

    result["hitPoints"] = 120;
    DataAccess->savePlayerData(result);

    result = DataAccess->getPlayerData("gorthaur");
    ExpectEq(120, result["hitPoints"]);
}
