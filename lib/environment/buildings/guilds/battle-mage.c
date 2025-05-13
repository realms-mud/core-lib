//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("battle mage guild");
    InteriorType("arcane war college");
    setFloorPlanType("military guild hall");

    addTimeOfDayDescription("dawn", ({
        ". Faint magical sparks dance above the training yard as runes glow dimly in the early light"
        }));
    addTimeOfDayDescription("morning", ({
        ". Chants of incantation blend with the clang of steel as apprentices drill with staves and swords"
        }));
    addTimeOfDayDescription("noon", ({
        ". The courtyard rings with energy, both magical and physical, as battle mages spar under a blazing sun"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The air smells faintly of ozone and burnt metal from recent spellfire exercises"
        }));
    addTimeOfDayDescription("evening", ({
        ". Arcane sigils etched into the walls begin to glow brighter, and magical lights flicker above the gates"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The fading light reveals the shimmer of protective wards around the guild’s perimeter"
        }));
    addTimeOfDayDescription("night", ({
        " illuminated by enchanted braziers and rune-beacons, with instructors leading quiet magical meditations"
        }));
    addTimeOfDayDescription("late night", ({
        " cloaked in stillness, though magical glyphs continue to pulse faintly along its walls"
        }));
    addTimeOfDayDescription("midnight", ({
        " encased in silence, disturbed only by the distant crack of energy as night sentinels maintain their vigilance"
        }));

    addSeasonDescription("winter", ({
        " with frost layering the outer wards, momentarily flashing blue where cold meets magic"
        }));
    addSeasonDescription("spring", ({
        " with flowering herbs growing in enchanted beds, used to focus spellwork during training rituals"
        }));
    addSeasonDescription("summer", ({
        " blazing with activity as spells and swordplay echo across sunlit courtyards"
        }));
    addSeasonDescription("autumn", ({
        " with dry leaves swirling through the courtyard, caught in playful bursts of controlled wind magic"
        }));

    addSourceOfLight(8, "enchanted braziers and rune-glow", "night");

    addDescriptionTemplate("a fortified arcane war college, home to the battle mages");
    addNearDarkDescriptionTemplate("the broad outline of a towered complex, faintly glowing with arcane power");
    addLowLightDescriptionTemplate("a martial structure with magical light pulsing from beneath etched runes");
    addDimLightDescriptionTemplate("a stone hall surrounded by training circles and spell-engraved pillars");
    addSomeLightDescriptionTemplate("a formidable stronghold where battle mages train with spell and steel");
}