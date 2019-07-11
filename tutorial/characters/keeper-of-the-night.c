//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/monster.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Black-robed figure");
    short("Black-robed figure");
    addAlias("figure");
    addAlias("black-robed figure");
    addAlias("keeper");
    addAlias("keeper of the night");

    Gender(1);
    Race("human");
    SetUpPersonaOfLevel("keeper of the night", 3);
    addTrait("lib/instances/traits/educational/educated.c");

    setUpRandomEquipment(0);
}
