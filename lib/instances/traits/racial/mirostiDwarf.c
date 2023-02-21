//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "racial");
    addSpecification("name", "Mirosti Dwarf");
    addSpecification("description", "The year 1693 and the dragon Sylthasis will forever be cursed by the dwarves\n"
        "of Mirost, for that was the year when their empire fell. Those who escaped the\n"
        "dragon were granted safety in Hillgarath. For this reason, Mirosti dwarves tend\n"
        "to be very friendly toward humans and high elves.\n");
    addSpecification("root", "dwarf");
    addSpecification("opposing root", "high elf");
    addSpecification("opinion", 10);
    addSpecification("opposing opinion", 5);
}
