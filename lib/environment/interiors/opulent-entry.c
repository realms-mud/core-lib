//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("opulent entry");

    addAdjectives(({
        "grand foyer with soaring ceilings and a sweeping marble staircase",
        "sunlit entry hall where crystal chandeliers cast rainbows on polished floors",
        "vestibule adorned with gilded mirrors and intricate plasterwork",
        "majestic entrance where towering columns frame double doors of carved oak",
        "lavish hall with mosaic floors and walls lined with priceless tapestries",
        "entryway where the scent of fresh flowers mingles with beeswax polish",
        "reception hall with a vaulted ceiling and stained glass windows",
        "welcoming entry chamber where a roaring hearth greets arriving guests",
        "palatial foyer with gold-leaf moldings and a domed painted ceiling",
        "refined entry where sunlight streams through arched windows onto silk rugs",
        "sumptuous hall with marble statues and vases overflowing with blooms",
        "bright entryway where lanterns and sconces reflect off crystal surfaces",
        "storied entrance where portraits of ancestors gaze down from paneled walls",
        "large vestibule with a grand piano and velvet-cushioned benches",
        "decorative hall where the air is perfumed with incense and fresh greenery",
        "great entry with a checkerboard floor and a sweeping double staircase",
        "festive foyer where banners and garlands hang for special occasions",
        "serene entryway where the hush of luxury is broken only by soft footsteps",
        "historic hall where the echoes of past celebrations linger in the air",
        "majestice and art-filled entry where sculptures and paintings line "
            "every available space",
        "gleaming vestibule with polished brass fixtures and carved stone archways",
        "warmly inviting entrance where the warmth of hospitality is felt immediately",
        "vaulted hall where sunlight dances across gold-inlaid mosaics",
        "chandelier-lit entry where the sparkle of crystal fills the air with light"
    }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy entry where only the faint glint of crystal and marble is "
        "visible in the darkness"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit entry hall, where the outlines of columns and staircases "
        "emerge from the gloom"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, the glow from lanterns and sconces revealing "
        "the opulence of the space"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##, sunlight streaming through tall windows to "
        "illuminate the grandeur of the entry"
    );
}
