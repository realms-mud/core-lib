//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("small limestone house");
    setFloorPlanType("house");

    addAdjectives(({
        "neat", "small", "pale", "limestone", "tidy", "modest"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## limestone house with a neatly thatched roof and "
        "small flower garden"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day gives the pale stone a gentle glow, the "
        "limestone almost luminous in the early morning light",
        ". At dawn, the small house stands quiet but welcoming, its light-colored "
        "walls catching the first rays while shadows still pool around it"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning reveals the careful stonework, each block of limestone cut "
        "and placed with precision despite the house's modest size",
        ". The small dwelling brightens in morning light, its pale walls "
        "reflecting rather than absorbing the sun's growing warmth"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the limestone almost gleams white in the sun, making the "
        "small house appear bright and cheerful",
        ". The shadows shrink to almost nothing at noon, leaving the small "
        "house bathed in light that emphasizes its tidy appearance"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light brings out subtle variations in the limestone, "
        "from cream to pale gold across the carefully fitted blocks",
        ". Shadows begin to stretch from the small structure, the sun warming "
        "the western wall as the day progresses"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, the limestone takes on a warmer hue, and soft "
        "light appears in the small window by the door",
        ". The house seems to glow softly at evening, the pale stone holding "
        "the day's last light longer than the surrounding landscape"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the limestone house becomes a lighter shape against the "
        "gathering darkness, its pale walls visible even as details fade",
        ". The small dwelling appears almost ghostly as night falls, the light "
        "color of its walls making it stand out when other features disappear"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, moonlight often reflects off the pale limestone, giving "
        "the small house an ethereal quality in the darkness",
        ". The house becomes a subtle landmark by night, its light-colored walls "
        "catching what little illumination there is"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with carefully tended flowers beginning to bloom in neat beds "
        "alongside the pale walls",
        " where spring rain darkens the thatch to a rich brown, contrasting "
        "beautifully with the light-colored stone below"
        }));

    addSeasonDescription("summer", ({
        " with climbing roses blooming against the limestone walls and the "
        "thatch dried to a golden hue by the summer sun",
        " surrounded by a profusion of colorful flowers that complement the "
        "subtle cream tones of the limestone walls"
        }));

    addSeasonDescription("autumn", ({
        " with a few late blossoms still brightening the garden and dried herbs "
        "hanging beside the door",
        " where fallen leaves gather at the foundation, their rich colors "
        "striking against the pale limestone walls"
        }));

    addSeasonDescription("winter", ({
        " with snow on the thatched roof and ice crystals forming delicate "
        "patterns on the small window",
        " where the limestone walls stand out starkly against the winter "
        "landscape, pale stone against white snow"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a small, pale shape with what appears to be a thatched roof"
    );
    addLowLightDescriptionTemplate(
        "a small light-colored structure with a thatched roof"
    );
    addDimLightDescriptionTemplate(
        "a neat limestone house with a thatched roof and a small garden"
    );
    addSomeLightDescriptionTemplate(
        "a small, well-kept limestone house with a neatly thatched roof, "
        "shuttered window, and a tiny but colorful flower garden"
    );

    // Single item template
    addItemTemplate(
        "The small limestone house exhibits a level of refinement unusual for "
        "its modest size. Built of pale, carefully cut limestone blocks, its "
        "walls rise evenly to meet a neatly thatched roof with decorative "
        "ridge work. A single window with painted shutters adorns the front, "
        "while the wooden door features simple but elegant ironwork. What the "
        "house lacks in size, it makes up for in careful details and "
        "maintenance, from the swept path to the tiny but meticulously kept "
        "flower garden alongside one wall."
    );

    addSourceOfLight(2);
}
