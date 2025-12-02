//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("dais");
    addAlias("platform");
    addAlias("raised platform");
    addAlias("stage");

    addAdjectives(({ "wooden", "broad", "raised", "carved", "old", "plain",
        "sturdy", "worn", "polished", "functional" }));

    addDescriptionTemplate("a ##Adjective## dais raised above the floor");

    addItemTemplate(
        "This dais is a broad, raised platform made from thick wooden planks. "
        "It is used to elevate a throne, table, or speaker above the rest of "
        "the hall. The edges are worn smooth by many feet."
    );

    addSomeLightDescriptionTemplate(
        "a wooden dais stands at one end of the hall, its surface polished smooth"
    );
    addDimLightDescriptionTemplate(
        "a dais is visible in the gloom, its outline broad and raised"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a dais can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a dais is present, but details are lost in the "
        "darkness"
    );
}
