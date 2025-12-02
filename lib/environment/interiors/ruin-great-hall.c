//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ruin great hall");

    addAdjectives(({
        "formerly-magnificent great hall with fallen chandeliers and crumbled walls",
        "vast chamber where rain now falls through gaping holes in the vaulted ceiling",
        "former feasting hall where rotted trestle tables lie broken and scattered",
        "imposing audience chamber now home only to debris and echoing emptiness",
        "cavernous hall where faded tapestries hang in tatters from crumbling walls",
        "noble gathering space where weeds grow between cracked marble floor tiles",
        "long-neglected great hall with a massive hearth now filled with rubble",
        "grand chamber where statues of lords and ladies lie toppled and broken",
        "ruined ceremonial space where birds nest in the rafters that remain standing",
        "former seat of power where throne daises stand empty and weather-worn",
        "massive hall where broken stained glass crunches underfoot",
        "ghostly banqueting space where the shadows of revelers exist only in memory",
        "skeletal great room where exposed roof beams create striped shadows",
        "decaying great hall where moss covers the once-polished stone benches",
        "fallen hall of state where rainwater pools beneath holes in the roof",
        "crumbling feast hall where elegant carvings are worn smooth by the elements",
        "hollow chamber whose size still hints at its former grandeur and importance",
        "roofless great hall where sunlight now illuminates what candles once did",
        "decadent chamber now stripped of gilding and ornamentation by time and thieves"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy great hall barely visible in the darkness, where only the "
        "massive scale of the chamber can be sensed through the gloom. The cold "
        "echoes of your movements suggest enormous empty space surrounding you"
    );

    addLowLightDescriptionTemplate(
        "a dimly visible great hall, a cavernous space where faint moonlight or "
        "distant torchlight reveals hints of fallen grandeur - toppled columns, "
        "broken furniture, and the suggestion of faded decorations on the walls"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, where the partial light enhances the sense "
        "of decay. What once must have been a place of feasting and ceremony now "
        "stands silent and broken, with enough light to navigate the debris but "
        "shadows still hiding the full extent of the ruin"
    );

    addSomeLightDescriptionTemplate(
        "a well-illuminated ##Adjective##. The light reveals the enormous scale "
        "of what was once clearly the heart of this place - a vast chamber where "
        "lords held court and feasts were celebrated. Now fallen stones, rotted "
        "wood, and the occasional glint of what might have been precious metal "
        "ornamentation tell the story of its decline"
    );
}
