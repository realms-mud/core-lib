//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Ammo;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Ammo = clone_object("/lib/items/ammunition.c");
    Ammo->set("name", "quiver");
    Ammo->set("short", "A quiver");
    Ammo->set("ammunition type", "arrow");
    Ammo->set("max capacity", 24);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Ammo);
}

/////////////////////////////////////////////////////////////////////////////
void IdReturnsTrueForAmmunitionType()
{
    ExpectTrue(Ammo->id("arrow"));
}

/////////////////////////////////////////////////////////////////////////////
void ShortReturnsCorrectMessageWhenEmpty()
{
    ExpectEq("A quiver that is empty (24 max)", 
        Ammo->short(), "short() returns correct value");
}

/////////////////////////////////////////////////////////////////////////////
void ShortReturnsCorrectMessageWhenOneItemInContainer()
{
    Ammo->set("quantity", 1);

    ExpectEq("A quiver containing 1 arrow (24 max)", Ammo->short());
}

/////////////////////////////////////////////////////////////////////////////
void AddAmmunitionAddsTheDesiredQuantityToTheContainer()
{
    Ammo->set("quantity", 1);

    ExpectEq(0, Ammo->addAmmunition(4));
    ExpectEq("A quiver containing 5 arrows (24 max)", Ammo->short());
}

/////////////////////////////////////////////////////////////////////////////
void AddingAmmunitionAboveCapacityReturnsLeftOverAmmo()
{
    Ammo->set("quantity", 10);

    ExpectEq(6, Ammo->addAmmunition(20));
    ExpectEq("A quiver containing 24 arrows (24 max)", Ammo->short());
}
