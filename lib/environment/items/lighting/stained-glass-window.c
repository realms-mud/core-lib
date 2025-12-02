//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("stained glass window");
    addAlias("stained-glass window");
    addAlias("colored window");

    addItemTemplate(
        "The stained glass window is set into a thick stone wall, its vibrant "
        "panes arranged in intricate patterns. Each piece of colored glass is "
        "held in place by slender strips of lead, forming scenes of artistry "
        "and devotion. When light passes through, the room is bathed in a "
        "kaleidoscope of shifting colors."
    );

    addNearDarkDescriptionTemplate(
        "the outline of a stained glass window is barely visible, its colors "
        "lost in the gloom"
    );
    addLowLightDescriptionTemplate(
        "a stained glass window glimmers faintly, its colors muted but hints "
        "of blue and red can be seen"
    );
    addDimLightDescriptionTemplate(
        "a stained glass window lets in a pale, colored glow, casting faint "
        "patches of color on the floor"
    );
    addSomeLightDescriptionTemplate(
        "soft daylight filters through the stained glass window, painting the "
        "room with gentle hues of red, blue, and gold"
    );
    addDescriptionTemplate(
        "sunlight streams through the stained glass window, filling the room "
        "with brilliant patterns of color that dance across the walls and floor"
    );
    useExteriorLighting();
}
