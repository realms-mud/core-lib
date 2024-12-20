//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include <functionlist.h>

object Destruct;
object Wizard;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database.PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(database.GetWizardOfLevel("elder"));

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
    Destruct = clone_object("/lib/tests/support/master/securityHelper.c");
    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard.restore("earl");
    setUsers(({ Wizard }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Destruct);
    destruct(Wizard);
}

/////////////////////////////////////////////////////////////////////////////
void InteractiveObjectsAreMovedToSafety()
{
    Destruct.ToggleInteractive(Wizard);

    object room = load_object("/lib/tests/support/environment/startingRoom.c");

    move_object(Wizard, room);
    ExpectEq(room, environment(Wizard));

    Destruct.prepare_destruct(room);

    ExpectEq(load_object("/secure/master.c"), environment(Wizard));
}

/////////////////////////////////////////////////////////////////////////////
void NonInteractiveObjectsAreDestroyed()
{
    object room = load_object("/lib/tests/support/environment/startingRoom.c");

    move_object(Wizard, room);
    ExpectEq(room, environment(Wizard));

    Destruct.prepare_destruct(room);

    ExpectFalse(Wizard);
}

/////////////////////////////////////////////////////////////////////////////
void DestructTraversesNestedInventories()
{
    object room = load_object("/lib/tests/support/environment/startingRoom.c");

    object item = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(item, Wizard);

    object material = clone_object("/lib/instances/items/materials/metal/iron.c");
    move_object(material, item);

    object item2 = clone_object("/lib/instances/items/weapons/swords/short-sword.c");
    move_object(item2, room);

    move_object(Wizard, room);
    ExpectEq(room, environment(Wizard));

    Destruct.prepare_destruct(room);

    ExpectFalse(Wizard);
    ExpectFalse(item);
    ExpectFalse(item2);
    ExpectFalse(material);
}

/////////////////////////////////////////////////////////////////////////////
void DestructDoesNotTraverseNestedInventoriesOfInteractiveObjects()
{
    Destruct.ToggleInteractive(Wizard);
    object room = load_object("/lib/tests/support/environment/startingRoom.c");

    object item = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(item, Wizard);

    object material = clone_object("/lib/instances/items/materials/metal/iron.c");
    move_object(material, item);

    object item2 = clone_object("/lib/instances/items/weapons/swords/short-sword.c");
    move_object(item2, room);

    move_object(Wizard, room);
    ExpectEq(room, environment(Wizard));

    Destruct.prepare_destruct(room);

    ExpectTrue(Wizard);
    ExpectTrue(item);
    ExpectFalse(item2);
    ExpectTrue(material);
}
