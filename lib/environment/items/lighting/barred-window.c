//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("barred window");
    addAlias("window");
    addAlias("iron-barred window");

    addItemTemplate(
        "The window is set with thick iron bars, their surfaces pitted with "
        "rust. The glass behind the bars is grimy, and the outside world is "
        "seen only through the narrow gaps."
    );

    addNearDarkDescriptionTemplate(
        "the outline of a barred window is barely visible, the bars lost in "
        "the gloom"
    );
    addLowLightDescriptionTemplate(
        "a barred window is a dim rectangle, the iron bars casting faint "
        "shadows"
    );
    addDimLightDescriptionTemplate(
        "a barred window lets in a pale, silvery glow through the iron bars"
    );
    addSomeLightDescriptionTemplate(
        "soft daylight filters through the barred window, the bars casting "
        "dark lines on the floor"
    );
    addDescriptionTemplate(
        "sunlight streams through the barred window, creating stark shadows "
        "across the room"
    );
    useExteriorLighting();
}
