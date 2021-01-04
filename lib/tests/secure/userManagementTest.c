//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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

    playerData["name"] = "dwight";
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

    clone_object("/lib/tests/support/services/catchShadow.c")->beginShadow(Wizard);

    setUsers(({ Wizard, Player }));

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
    object player = clone_object("/lib/realizations/player.c");
    player->restore("fred");

    object wizard = clone_object("/lib/realizations/wizard.c");
    wizard->restore("harold");

    set_this_player(player);
    ExpectFalse(Users->createWizard("gorthaur"), "fred failed to wiz gorthaur");

    set_this_player(wizard);
    ExpectFalse(Users->createWizard("gorthaur"), "harold failed to wiz gorthaur");

    destruct(player);
}

/////////////////////////////////////////////////////////////////////////////
void CreateWizardSucceedsIfSponsorValid()
{
    ExpectEq("lib/realizations/player.c",
        program_name(findPlayer("gorthaur")));

    ExpectFalse(Users->createWizard("gorthaur"), "no sponsor set");

    set_this_player(Wizard);
    ExpectTrue(Users->createWizard("gorthaur"), "earl wizzed gorthaur");
    ExpectEq("lib/realizations/wizard.c",
        program_name(findPlayer("gorthaur")));
}

/////////////////////////////////////////////////////////////////////////////
void CreateWizardSucceedsForOfflineWizard()
{
    destruct(Player);
    ExpectFalse(findPlayer("dwight"));

    object wizard = clone_object("/lib/realizations/wizard.c");
    wizard->restore("dwight");
    ExpectEq("player", wizard->wizardLevel());
    destruct(wizard);

    set_this_player(Wizard);
    ExpectTrue(Users->createWizard("dwight", "creator"), "earl wizzed dwight");

    wizard = clone_object("/lib/realizations/wizard.c");
    wizard->restore("dwight");
    ExpectEq("creator", wizard->wizardLevel());
}
