//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "professional");
    addSpecification("name", "master arcane craftsman");
    addSpecification("description", "You are a master arcane craftsman");
    addSpecification("root", "arcane craftsman");
    addSpecification("opinion", 5);
    addSpecification("bonus engineering", 25);
    addSpecification("bonus mathematics", 20);
    addSpecification("bonus physics", 20);
    addSpecification("bonus spellcraft", 20);
    addSpecification("bonus evocation", 15);
    addSpecification("bonus transformation", 15);
    addSpecification("bonus manipulation", 15);
    addSpecification("bonus elemental air", 15);
    addSpecification("bonus elemental earth", 15);
    addSpecification("bonus elemental fire", 15);
    addSpecification("bonus elemental water", 15);
    addSpecification("bonus magical essence", 15);
}
