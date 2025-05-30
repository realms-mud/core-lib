//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("limestone house");
    setFloorPlanType("house");

    addAdjectives(({
        "elegant", "pale", "solidly-built", "limestone", "handsome", "comfortable"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## limestone house with a slate roof and neatly arranged "
        "garden"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the pale stone walls, giving them a "
        "soft golden glow that enhances their natural beauty",
        ". At dawn, the house appears almost ethereal, the limestone luminous "
        "in the early light while shadows still linger around its base"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning light reveals the quality of the stonework, each block "
        "precisely cut and fitted to create a facade of quiet elegance",
        ". The limestone walls brighten in the growing light, reflecting rather "
        "than absorbing the sun's warmth"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the house presents a picture of solidity and permanence, "
        "the pale limestone almost gleaming in the direct sun",
        ". The crisp edges of the limestone blocks cast sharp shadows at noon, "
        "emphasizing the precision of the house's construction"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light brings a warm cast to the limestone, softening "
        "its appearance while highlighting the skilled masonry",
        ". Shadows begin to lengthen across the garden as afternoon progresses, "
        "the sun warming the western wall of the handsome dwelling"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, golden lamplight begins to shine from the "
        "windows, complementing the warm tones the setting sun brings to the "
        "limestone",
        ". The house seems most inviting at evening, when the pale stone holds "
        "the day's last light and windows glow with welcome"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the limestone house remains visible longer than its "
        "surroundings, its pale walls holding the light as darkness gathers",
        ". The last rays of sun catch on the uppermost stones as dusk falls, "
        "giving the house a crown of gold before night claims it"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the pale walls seem to glow faintly in the moonlight, the "
        "limestone house a ghostly presence in the darkness",
        ". Lamplight spills from several windows, creating pools of gold "
        "against the silvered limestone walls"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with carefully planned flower beds beginning to show color and fresh "
        "paint brightening the window frames and door",
        " where climbing roses send new green shoots up trellises placed "
        "strategically against the pale stone walls"
        }));

    addSeasonDescription("summer", ({
        " with windows open behind lace curtains and flowering vines adding "
        "color to the elegant limestone facade",
        " surrounded by a garden in full bloom, the colorful flowers providing "
        "a perfect complement to the pale stone walls"
        }));

    addSeasonDescription("autumn", ({
        " with ivy turning crimson against the limestone and garden beds being "
        "prepared for winter's dormancy",
        " where the slanting autumn light brings out subtle variations in the "
        "stone, from cream to pale gold across the facade"
        }));

    addSeasonDescription("winter", ({
        " with smoke rising from the chimneys and snow outlining every "
        "architectural detail of the handsome structure",
        " where frost creates delicate patterns on the windows, adding temporary "
        "decoration to the dignified limestone facade"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a light-colored building with what appears to be a slate roof"
    );
    addLowLightDescriptionTemplate(
        "a pale stone house with multiple windows and a well-kept garden"
    );
    addDimLightDescriptionTemplate(
        "a limestone house with a slate roof and neatly arranged garden beds"
    );
    addSomeLightDescriptionTemplate(
        "an elegant limestone house with precisely fitted blocks, a slate roof, "
        "multiple windows with painted shutters, and a formal garden"
    );

    // Single item template
    addItemTemplate(
        "The limestone house represents comfortable prosperity, constructed of "
        "pale, carefully dressed stone blocks laid in precise courses. The "
        "slate roof features proper eaves and gutters to protect the walls from "
        "rain damage, while multiple windows with painted shutters allow ample "
        "light into the interior. A stone path leads through a well-planned "
        "garden to the front door, which is framed by decorative stonework. The "
        "overall impression is one of quiet elegance and permanence, neither "
        "ostentatious nor humble."
    );

    addSourceOfLight(3);
}
