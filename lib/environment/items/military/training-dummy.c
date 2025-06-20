//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("training dummy");
    addAlias("dummy");
    addAlias("pell");

    addAdjectives(({ "straw", "padded", "humanoid", "practice", "worn" }));
    addDescriptionTemplate("a ##Adjective## training dummy mounted on a wooden post");

    addItemTemplate(
        "The training dummy is a sturdy post wrapped in layers of straw and "
        "canvas. Its surface is battered and scarred from countless blows, and "
        "bits of straw poke out from beneath the wrappings. The ground nearby "
        "is trampled by the feet of many trainees."
    );

    addNearDarkDescriptionTemplate(
        "the outline of a training dummy is barely visible, its shape lost in "
        "the gloom"
    );
    addLowLightDescriptionTemplate(
        "a training dummy stands in the shadows, its battered form hard to "
        "distinguish"
    );
    addDimLightDescriptionTemplate(
        "the training dummy is faintly illuminated, its straw wrappings just "
        "visible"
    );
    addSomeLightDescriptionTemplate(
        "the training dummy is clearly visible, its battered surface showing "
        "signs of heavy use"
    );
    addDescriptionTemplate(
        "sunlight shines on the training dummy, making every scar and patch of "
        "straw stand out"
    );
}
