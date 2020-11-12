//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Environment;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Environment = clone_object("/lib/tests/support/environment/testEnvironment.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Environment);
}

/////////////////////////////////////////////////////////////////////////////
void CanAddShop()
{
    Environment->testAddShop("/lib/environment/shopInventories/swordsmith.c");
    ExpectEq("lib/environment/shopInventories/swordsmith.c", Environment->getShop());
}

/////////////////////////////////////////////////////////////////////////////
void ShopInventoryUpdatesOnReset()
{
    Environment->testAddShop("/lib/environment/shopInventories/swordsmith.c");
    Environment->getShop()->resetInventory();
    ExpectEq(0, sizeof(Environment->getShop()->storeInventory()));
    Environment->reset();
    ExpectTrue(15 < sizeof(Environment->getShop()->storeInventory()));
}

/////////////////////////////////////////////////////////////////////////////
void CanOnlyAddOneShop()
{
    Environment->testAddShop("/lib/environment/shopInventories/swordsmith.c");

    string expected = "*ERROR in environment.c: a shop has already been assigned to this environment.\n";
    string err = catch (Environment->testAddShop("/lib/environment/shopInventories/tailor.c"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void AddShopRaisesErrorIfInvalidObjectPassed()
{
    string expected = "*ERROR in environment.c: '/lib/tests/bad/path.c' is not a valid shop.\n";
    string err = catch (Environment->testAddShop("/lib/tests/bad/path.c"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void AddShopRaisesErrorIfPassedFileIsNotAShop()
{
    string expected = "*ERROR in environment.c: '/lib/environment/environment.c' is not a valid shop.\n";
    string err = catch (Environment->testAddShop("/lib/environment/environment.c"));
    ExpectEq(expected, err);
}
