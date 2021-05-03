//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        clone_object("/lib/modules/secure/dataServices/authenticationDataService.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(DataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void GetCharactersReturnsListOfUserCharacters()
{
    DataAccess.saveUser("earl", "earl", "127.0.0.1");

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(Database.GetWizardOfLevel("owner", "earl"));

    mapping gorthaur = Database.Gorthaur();
    gorthaur["userName"] = "earl";

    dataAccess.savePlayerData(gorthaur);

    gorthaur["name"] = "george";
    dataAccess.savePlayerData(gorthaur);
    destruct(dataAccess);

    ExpectEq(({ "earl", "gorthaur", "george" }), 
        DataAccess.getCharacters("earl"));
}

/////////////////////////////////////////////////////////////////////////////
void AuthenticateUserReturnsNoUserWhenUserDoesNotExist()
{
    ExpectEq("no user", DataAccess.authenticateUser("fred", "fred"));
}

/////////////////////////////////////////////////////////////////////////////
void AuthenticateUserReturnsFailedWhenPasswordIncorrect()
{
    DataAccess.saveUser("fred", "password", "127.0.0.1");

    ExpectEq("failed", DataAccess.authenticateUser("fred", "fred"));
}

/////////////////////////////////////////////////////////////////////////////
void AuthenticateUserReturnsAuthenticatedWhenPasswordCorrect()
{
    DataAccess.saveUser("fred", "password", "127.0.0.1");

    ExpectEq("authenticated", DataAccess.authenticateUser("fred", "password"));
}

/////////////////////////////////////////////////////////////////////////////
void UserExistsReturnsCorrectly()
{
    ExpectFalse(DataAccess.userExists("dwight"));
    DataAccess.saveUser("dwight", "password", "127.0.0.1");
    ExpectTrue(DataAccess.userExists("dwight"));
}
