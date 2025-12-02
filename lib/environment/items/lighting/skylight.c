//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("skylight");
    suppressEntryMessage();

    addItemTemplate("It is difficult to discern the details of the skylight "
        "from this distance, but it appears that there is a thin, opaque "
        "surface covering it from the outside world");

    addNearDarkDescriptionTemplate("the faintest hint of light is coming "
        "from somewhere above");
    addLowLightDescriptionTemplate("far above, the faint outline of a "
        "slightly brighter rectangle - probably a skylight allowing in the "
        "starlight or perhaps the cloud-covered moon");
    addDimLightDescriptionTemplate("far above, a skylight is allowing the "
        "moon light to shine into the chamber");
    addSomeLightDescriptionTemplate("far above, a skylight is allowing "
        "light from outside to come into the chamber");
    addDescriptionTemplate("far above, a skylight is allowing the sun's "
        "light into the chamber");
    useExteriorLighting();
}
