//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("coral-domed sanctuary");

    addAdjectives(({
        "serene chamber beneath a dome of pale coral",
        "sanctuary with walls shaped from living coral",
        "softly glowing room beneath a coral arch",
        "peaceful dome where delicate coral forms natural carvings",
        "hushed sanctuary of pink and ivory coral",
        "organic chamber where coral and stone blend seamlessly"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowed sanctuary. The coral dome looms faintly in the darkness.");
    addLowLightDescriptionTemplate("a dim coral sanctuary. Light barely reaches the curves of the dome.");
    addDimLightDescriptionTemplate("a softly-lit ##Adjective##, the coral casting gentle hues");
    addSomeLightDescriptionTemplate("a tranquil ##Adjective##, light glinting off the curved coral surfaces");
}
