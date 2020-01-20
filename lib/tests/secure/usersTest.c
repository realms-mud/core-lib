//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include <functionlist.h>

object Users;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    string *functions = filter(
        functionlist(this_object(), RETURN_FUNCTION_NAME),
        (: sizeof(regexp(({ $1 }), "__inline")) :));

    ignoreList += functions;
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Users = clone_object("/secure/simul_efun.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Users);
}

/////////////////////////////////////////////////////////////////////////////
void LivingObjectsPlacedInList()
{
    ExpectEq(0, Users->findLiving("bob"));

    object critter = clone_object("/lib/realizations/monster.c");
    critter->Name("bob");
    Users->addLiving(critter);

    ExpectEq(critter, Users->findLiving("bob"));

    destruct(critter);
    ExpectEq(0, Users->findLiving("bob"));
}

/////////////////////////////////////////////////////////////////////////////
void FindLivingCanFindPlayers()
{
    ExpectEq(0, Users->findLiving("bob"));

    object critter = clone_object("/lib/realizations/player.c");
    critter->Name("bob");
    setUsers(({ critter }));

    Users->addLiving(critter);

    ExpectEq(critter, Users->findLiving("bob"));

    destruct(critter);
    ExpectEq(0, Users->findLiving("bob"));
}

/////////////////////////////////////////////////////////////////////////////
void FindLivingCanFindWizards()
{
    ExpectEq(0, Users->findLiving("bob"));

    object critter = clone_object("/lib/realizations/wizard.c");
    critter->Name("bob");
    setUsers(({ critter }));

    Users->addLiving(critter);

    ExpectEq(critter, Users->findLiving("bob"));

    destruct(critter);
    ExpectEq(0, Users->findLiving("bob"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayersPlacedInUsersList()
{
    ExpectEq(({}), users());

    object player = clone_object("/lib/realizations/player.c");
    player->Name("earl");

    object wizard = clone_object("/lib/realizations/wizard.c");
    wizard->Name("fred");

    setUsers(({ player, wizard }));

    addLiving(player);
    addLiving(wizard);

    ExpectEq(({ player, wizard }), users());

    destruct(player);
    ExpectEq(({ wizard }), users());
}
