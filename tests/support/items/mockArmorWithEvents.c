//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

object TestFixture;

/////////////////////////////////////////////////////////////////////////////
public void SetTestFixture(object fixture)
{
    TestFixture = fixture;
}

/////////////////////////////////////////////////////////////////////////////
public void onEquip()
{
    // The test needs to catch these exceptions. It was the most elegant way I
    // could derive to test events.
    raise_error("event handler: onEquip called");
}

/////////////////////////////////////////////////////////////////////////////
public void onUnequip()
{
    raise_error("event handler: onUnequip called");
}

/////////////////////////////////////////////////////////////////////////////
public void equipMethod()
{
    raise_error("event handler: equipMethod called");
}

/////////////////////////////////////////////////////////////////////////////
public void unequipMethod()
{
    raise_error("event handler: unequipMethod called");
}

