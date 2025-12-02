//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bed");
    addAlias("wooden bed");
    addAlias("simple bed");
    addAlias("sleeping cot");

    addAdjectives(({ "wooden", "simple", "broad", "old", "sturdy", "plain",
        "functional", "worn", "low", "rectangular" }));

    addDescriptionTemplate("a ##Adjective## bed with a straw-filled mattress");

    addItemTemplate(
        "This bed is made from sturdy wood, its frame low and broad. The "
        "mattress is stuffed with straw and covered with a rough linen sheet. "
        "The headboard is plain, and the legs are thick and stable."
    );

    addSomeLightDescriptionTemplate(
        "a wooden bed stands against the wall, its mattress covered in linen"
    );
    addDimLightDescriptionTemplate(
        "a bed is visible in the gloom, its outline broad and low"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a bed can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a bed is present, but details are lost in "
        "the darkness"
    );
}
