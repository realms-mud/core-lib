//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Werric Knight Guild");
    InteriorType("arcane war college");
    setFloorPlanType("guild");

    addTimeOfDayDescription("dawn", ({
        ". The rising sun casts its first light upon the guild's high walls. Devoted knights gather in the sacred hall, kneeling "
        "before the altar of Werra to offer prayers for strength in the coming day's battles"
        }));
    addTimeOfDayDescription("morning", ({
        ". The guild hall is alive with the sound of armor being donned and weapons being sharpened. The knights prepare for their daily training, invoking the name of Werra as they ready themselves for combat"
        }));
    addTimeOfDayDescription("noon", ({
        ". The sound of swords clashing echoes through the hall as the knights spar in the training grounds. Some meditate in the temple area, seeking Werra's guidance for their next campaign"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The air is thick with the scent of steel and leather as the knights perfect their combat techniques. Some gather in the war room to study maps, others chant prayers to Werra, seeking divine favor"
        }));
    addTimeOfDayDescription("evening", ({
        ". As the sun sets, the knights come together in the great hall for a communal meal. Stories of past battles are shared, and songs of victory dedicated to Werra fill the air"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The guild hall is quiet, save for the soft chanting from the temple. The knights prepare for their nightly watch, praying to Werra for protection and guidance"
        }));
    addTimeOfDayDescription("night", ({
        " when the flickering light of torches casts long shadows in the hall. A sense of solemnity fills the air as knights gather around the altar to offer their nightly prayers to Werra, asking for strength in their dreams"
        }));
    addTimeOfDayDescription("late night", ({
        " when the hall is mostly still. Only the most devout knights remain in the sacred hall, kneeling before the altar in reverence, offering their personal prayers and preparing themselves spiritually for the next battle"
        }));
    addTimeOfDayDescription("midnight", ({
        " when the guild is quiet, and only the whispers of fervent prayers can be heard. The warriors are deep in their rest, but their spirits remain devoted to Werra"
        }));

    addSeasonDescription("winter", ({
        " when the chill outside strengthens the resolve of the knights within. The warmth of the hearth and the sacred fires of Werra's altar keep the guild hall vibrant with energy. The knights train harder, preparing for the long winter battles"
        }));
    addSeasonDescription("spring", ({
        " when the guild hall bustles with energy as knights prepare for the seasonal campaigns. They gather in the war room to plan their next moves, with divine guidance from Werra's influence"
        }));
    addSeasonDescription("summer", ({
        " when the guild hall is filled with the heat of battle preparations. The knights train in the scorching sun, invoking Werra's strength to withstand the elements and grow stronger in combat"
        }));
    addSeasonDescription("autumn", ({
        " when the guild hall echoes with the anticipation of future wars. The knights are seen at their most disciplined, as they perform rituals and preparations for the coming conflicts that the new season will bring"
        }));

    addSourceOfLight(5, "sacred torches, lanterns, and glowing glyphs of Werra", "night");

    addDescriptionTemplate("a large fortress-like guild hall adorned with sacred symbols of Werra, banners of the guild, and war trophies. The air is filled with the sound of clashing swords, chants of prayers, and the focus of knights preparing for battle");
    addNearDarkDescriptionTemplate("a stone building with glowing embers from torches reflecting off the walls, and the distant sound of fervent prayers being whispered");
    addLowLightDescriptionTemplate("a grand hall illuminated by flickering torches and candles, with knights kneeling before the altar and practicing their combat skills in the background");
    addDimLightDescriptionTemplate("a war room filled with maps, statues of Werra, and the faint glow of sacred symbols lighting the walls. Warriors prepare for their next campaign, guided by divine favor");
    addSomeLightDescriptionTemplate("a large temple-like hall, with banners displaying the emblem of Werra, and knights training under the divine influence of the god of war, their weapons gleaming with holy power");
}
