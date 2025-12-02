//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Knights of the Storm Guild Hall");
    InteriorType("thunderous keep and arcane chambers");
    setFloorPlanType("guild");

    addTimeOfDayDescription("dawn", ({
        ". The sky above the guild hall crackles with distant thunder, and the first rays of light are drowned by the ominous storm clouds gathering overhead"
        }));
    addTimeOfDayDescription("morning", ({
        ". The sound of crackling lightning can be heard in the distance as dark clouds swirl above, while the knights prepare for the day's battle in their lightning-infused armors"
        }));
    addTimeOfDayDescription("noon", ({
        ". The midday sun struggles to pierce the heavy clouds overhead, casting an eerie glow on the metal towers that hum with arcane energy, while occasional flashes of lightning brighten the gloom"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The air is thick with the scent of ozone as the knights train with their thunderous weapons, sparks dancing in the air as their magic intertwines with their sword strikes"
        }));
    addTimeOfDayDescription("evening", ({
        ". As the sun sets, the guild hall's iron spires gleam with an unnatural light, the crackling sound of arcane energy rising to a crescendo as the storm intensifies"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The sky darkens, and the guild hall glows with flickering lightning as the knights prepare for their nocturnal raids, their weapons crackling with dark energy"
        }));
    addTimeOfDayDescription("night", ({
        " when the storm finally breaks, thunder rolls through the air, and lightning strikes the towers of the guild hall with immense power, casting jagged shadows of armored figures"
        }));
    addTimeOfDayDescription("late night", ({
        " under the relentless storm, the guild hall pulses with dangerous energy, and the knights' chants echo across the grounds as they invoke the might of the storm"
        }));
    addTimeOfDayDescription("midnight", ({
        " when the guild hall is at its most terrifying, lightning crackling through the halls as if the very walls are alive with arcane power, and the knights prepare for their next blood-soaked mission"
        }));

    addSeasonDescription("winter", ({
        " with fierce snowstorms surrounding the guild hall, the cold only intensifies the crackling warmth of the lightning-powered forges within, as the knights prepare for battle against the elements"
        }));
    addSeasonDescription("spring", ({
        " with the storm clouds ever-present, the smell of fresh rain mixes with the ozone in the air, and the knights practice their lightning-infused combat techniques"
        }));
    addSeasonDescription("summer", ({
        " when the guild hall is suffused with a suffocating heat, the air thick with the electric energy of storms, as lightning strikes the tallest spires in the distance"
        }));
    addSeasonDescription("autumn", ({
        " with thunderstorms rolling in regularly, the knights ready their magical blades, preparing for the coming battles, the hall alive with flashes of lightning and the sound of thunder"
        }));

    addSourceOfLight(5, "arcane lightning and storm-forged lanterns", "night");

    addDescriptionTemplate("a foreboding stronghold where lightning strikes the earth and arcane warriors sharpen their deadly blades");
    addNearDarkDescriptionTemplate("a towering keep, dark storm clouds swirling above it, with flashes of lightning illuminating the iron spires");
    addLowLightDescriptionTemplate("a dark, imposing hall, the walls crackling with arcane energy, and lightning flashing outside as the knights prepare for battle");
    addDimLightDescriptionTemplate("a guild hall crackling with dark power, lightning flickering along the weapons of the knights and the walls themselves");
    addSomeLightDescriptionTemplate("a storm-battered keep, where arcane lightning and martial prowess meet in a deadly dance of power and violence");
}