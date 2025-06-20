//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("frosted window");
    addAlias("window");
    addAlias("frosted-glass window");

    addItemTemplate(
        "The window is made of frosted glass, its surface etched and clouded "
        "to obscure the view. Light passes through in a soft, diffuse glow, "
        "blurring the shapes beyond."
    );

    addNearDarkDescriptionTemplate(
        "the outline of a frosted window is barely visible, its glass "
        "clouded and dim"
    );
    addLowLightDescriptionTemplate(
        "a frosted window glows faintly, the outside world hidden behind a "
        "veil of glass"
    );
    addDimLightDescriptionTemplate(
        "a frosted window lets in a pale, diffuse glow, softening the room's "
        "edges"
    );
    addSomeLightDescriptionTemplate(
        "soft daylight filters through the frosted window, bathing the room "
        "in gentle light"
    );
    addDescriptionTemplate(
        "sunlight streams through the frosted window, filling the room with "
        "a warm, diffuse radiance"
    );
    useExteriorLighting();
}
