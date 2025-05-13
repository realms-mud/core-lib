//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Order of Ilyrth Guild Hall");
    InteriorType("stone temple and meditation halls");
    setFloorPlanType("guild");

    addTimeOfDayDescription("dawn", ({
        ". The first rays of sunlight bathe the guild hall in warm, golden light, and the soft scent of healing herbs fills the air as members of the Order begin their daily prayers and meditations"
        }));
    addTimeOfDayDescription("morning", ({
        ". The hall is alive with a quiet energy, as the healing arts are practiced, and gentle prayers are whispered in reverence to Ilyrth, the goddess of restoration and care"
        }));
    addTimeOfDayDescription("noon", ({
        ". The guild hall is peaceful, filled with light as healers gather to share knowledge, and the healing gardens outside bloom with vibrant flowers and restorative plants"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". Soft laughter and murmurs of conversation can be heard as the guild's members share in the work of healing, both physical and emotional, offering their gifts to those in need"
        }));
    addTimeOfDayDescription("evening", ({
        ". As the sun sets, the guild hall glows with a soft, warm light. The hall is quieter now, and healers and clerics alike meditate on their sacred mission to heal the world"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The setting sun casts a golden light across the hall, and the soft hum of divine energy can be felt as healers prepare to rest and replenish their strength for the work ahead"
        }));
    addTimeOfDayDescription("night", ({
        " when the guild hall is lit by soft candles and warm hearths. It is a time of quiet reflection and gentle prayers, as members of the Order offer their evening blessings to Ilyrth"
        }));
    addTimeOfDayDescription("late night", ({
        " when the guild hall is tranquil, the air filled with the peaceful hum of healing magic, and the faint light of divine symbols glows softly in the darkness"
        }));
    addTimeOfDayDescription("midnight", ({
        " when the guild hall is still and calm, only the faintest trace of healing energy lingering in the air as members of the Order rest and renew their energies for the coming day"
        }));

    addSeasonDescription("winter", ({
        " when the guild hall is a warm haven against the cold, filled with the fragrance of healing herbs and soft light that radiates comfort and hope, even as the world outside lies frozen"
        }));
    addSeasonDescription("spring", ({
        " when the guild hall blooms with life, both inside and outside in the sacred gardens, as new growth takes root, and members of the Order are energized by the goddess's restorative influence"
        }));
    addSeasonDescription("summer", ({
        " when the sun's warmth fills the hall with radiant light, and the gardens overflow with vibrant blossoms. The air is alive with the sounds of laughter and the joy of healing"
        }));
    addSeasonDescription("autumn", ({
        " when the trees around the guild hall glow with the colors of the harvest, and the air is filled with the scent of dried herbs and restorative teas, providing comfort and care"
        }));

    addSourceOfLight(5, "soft divine light and healing radiance", "night");

    addDescriptionTemplate("a peaceful sanctuary devoted to the goddess Ilyrth, where healing and divine grace radiate through every corner of the hall");
    addNearDarkDescriptionTemplate("a tranquil building illuminated by soft light, with serene gardens visible through the windows and an aura of calm surrounding it");
    addLowLightDescriptionTemplate("a hall bathed in gentle, divine light, where the presence of Ilyrth fills every corner, offering peace and restoration to all who enter");
    addDimLightDescriptionTemplate("a warm, welcoming hall filled with the soft glow of candles and divine symbols, where healers work tirelessly to soothe pain and restore the wounded");
    addSomeLightDescriptionTemplate("a sanctuary of healing, where the divine light of Ilyrth shines brightly and gently, and the gardens are filled with vibrant plants used for restorative purposes");
}
