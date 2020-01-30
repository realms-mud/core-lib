//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include <functionlist.h>

object Users;
object DataAccess;
object Player;
object Wizard;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");

    mapping playerData = database->Gorthaur();
    dataAccess->savePlayerData(playerData);

    playerData["name"] = "fred";
    dataAccess->savePlayerData(playerData);

    dataAccess->savePlayerData(database->GetWizardOfLevel("elder"));
    dataAccess->savePlayerData(database->GetWizardOfLevel("senior", "harold"));

    destruct(dataAccess);
    destruct(database);

    string *functions = filter(
        functionlist(this_object(), RETURN_FUNCTION_NAME),
        (: sizeof(regexp(({ $1 }), "__inline")) :));

    ignoreList += functions;
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Users = clone_object("/secure/master/user-management.c");
    DataAccess =
        clone_object("/lib/modules/secure/dataServices/authenticationDataService.c");

    Player = clone_object("/lib/realizations/player.c");
    Player->restore("gorthaur");

    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard->restore("earl");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Wizard);
    destruct(Player);
    destruct(DataAccess);
    destruct(Users);
}

/////////////////////////////////////////////////////////////////////////////
void RemoveCharacterCorrectlyRemovesCharacter()
{
    object player = clone_object("/lib/realizations/player.c");
    player->restore("fred");

    ExpectTrue(DataAccess->characterExists("fred"));

    ExpectFalse(Users->removeCharacter(player), "player not deleted");

    ExpectTrue(DataAccess->characterExists("fred"));

    set_this_player(player);
    ExpectTrue(Users->removeCharacter(player));
    ExpectFalse(DataAccess->characterExists("fred"), "fred character removed");
    ExpectFalse(player, "player destroyed");
}

/////////////////////////////////////////////////////////////////////////////
void CreateWizardFailsIfSponsorNotValid()
{
    object wizard = clone_object("/lib/realizations/wizard.c");
    wizard->restore("harold");

    object player = clone_object("/lib/realizations/player.c");
    player->restore("fred");

    set_this_player(player);
    ExpectFalse(Users->createWizard(Player), "fred failed to wiz gorthaur");

    set_this_player(wizard);
    ExpectFalse(Users->createWizard(Player), "harold failed to wiz gorthaur");
}

/////////////////////////////////////////////////////////////////////////////
void CreateWizardSucceedsIfSponsorValid()
{
    ExpectFalse(Users->createWizard(Player), "no sponsor set");

    set_this_player(Wizard);
    ExpectTrue(Users->createWizard(Player), "earl wizzed gorthaur");
}
