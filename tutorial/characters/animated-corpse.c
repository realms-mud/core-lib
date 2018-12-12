//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/monster.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("zombie");
    short("An animated corpse");
    addAlias("animated corpse");
    addAlias("corpse");

    Gender(1);
    Race("maegenstryd");
    SetUpPersonaOfLevel("swordsman", 1);
    setUpRandomEquipment(0);
}
