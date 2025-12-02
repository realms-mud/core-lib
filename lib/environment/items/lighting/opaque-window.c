//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("opaque window");
    addAlias("window");
    addAlias("clouded window");

    addItemTemplate(
        "The window's glass is completely opaque, clouded by age or purposefully "
        "treated to block all view. Only a faint glow betrays the presence of "
        "light beyond."
    );

    addNearDarkDescriptionTemplate(
        "the outline of an opaque window is barely visible, its glass blocking "
        "nearly all light"
    );
    addLowLightDescriptionTemplate(
        "an opaque window glows faintly, the outside world hidden behind a "
        "featureless surface"
    );
    addDimLightDescriptionTemplate(
        "an opaque window lets in a pale, diffuse glow, with no hint of what "
        "lies beyond"
    );
    addSomeLightDescriptionTemplate(
        "soft daylight filters through the opaque window, bathing the room in "
        "a gentle, featureless light"
    );
    addDescriptionTemplate(
        "sunlight streams through the opaque window, filling the room with a "
        "soft, even radiance"
    );
    useExteriorLighting();
}
