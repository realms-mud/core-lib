//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "racial");
    addSpecification("name", "Khazurathi Dwarf");
    addSpecification("description", "The nation of Khazurath is the last great bastion of the dwarves\n"
        "still extant. The dwarves of this nation tend to have grey eyes and black or brown\n"
        "hair, though deviations certainly exist. Their skin tone tends to be slightly\n"
        "darker than their northern cousins.\n");
    addSpecification("root", "dwarf");
    addSpecification("opposing root", "elf");
    addSpecification("opinion", 10);
    addSpecification("opposing opinion", -10);
}
