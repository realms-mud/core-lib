//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->Gorthaur());

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/realizations/player.c");
    Player->Name("ralph");
    Player->Race("elf");
    Player->addCommands();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerSavedAndQuitsWhenQuitIsCalled()
{
    object persistedPlayer = clone_object("/lib/realizations/player.c");
    persistedPlayer->restore("ralph");
    ExpectEq(0, persistedPlayer->Race());

    ExpectTrue(Player->executeCommand("quit"));
    ExpectFalse(objectp(Player));
    persistedPlayer = clone_object("/lib/realizations/player.c");
    persistedPlayer->restore("ralph");
    ExpectEq("elf", persistedPlayer->Race());
    destruct(persistedPlayer);
}

/////////////////////////////////////////////////////////////////////////////
void QuitDestroysFullInventory()
{
    object bag = clone_object("/lib/items/item.c");
    move_object(bag, Player);

    object bagItem1 = clone_object("/lib/items/weapon.c");
    move_object(bagItem1, Player);

    object bagItem2 = clone_object("/lib/items/armor.c");
    move_object(bagItem2, Player);

    object weapon = clone_object("/lib/items/weapon.c");
    move_object(weapon, Player);

    object armor = clone_object("/lib/items/armor.c");
    move_object(armor, Player);

    object effect = clone_object("/lib/items/modifierObject.c");
    move_object(effect, Player);

    ExpectTrue(Player->executeCommand("quit"));

    ExpectFalse(objectp(bag));
    ExpectFalse(objectp(bagItem1));
    ExpectFalse(objectp(bagItem2));
    ExpectFalse(objectp(weapon));
    ExpectFalse(objectp(armor));
    ExpectFalse(objectp(effect));
}
