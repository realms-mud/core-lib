//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef potions_h
#define potions_h

protected mapping potions =
([
    "healing potion":([
        "type": "health",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 5]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "increase hit points": 100,
            "biological": "analeptic",
        ]),
        "default description": "A luminous ruby-red liquid that gives off a faint warmth. Tiny "
            "motes of golden light swirl within, pulsing with life-restoring "
            "energy that mends wounds and knits flesh with magical efficiency.",
        "base experience": 5,
    ]),
    "mana potion":([
        "type": "health",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 5]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "increase spell points": 100,
            "biological": "analeptic",
        ]),
        "default description": "An ethereal azure fluid that subtly shifts and flows as if alive. "
            "Stardust-like motes float within its depths, and the potion "
            "emits a barely audible hum of arcane resonance when uncorked.",
        "base experience": 5,
    ]),
    "stamina potion":([
        "type": "health",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 5]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "increase stamina points": 100,
            "biological": "adrenaline",
        ]),
        "default description": "A vibrant emerald-green liquid with a scent of fresh pine and "
            "wild herbs. When swirled, it releases a brief flash of energy "
            "that tingles across the skin, promising renewed vigor and vitality.",
        "base experience": 5,
    ]),
    "tears of ilyrth":([
        "type": "power",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewEpicPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 35]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/tears-of-ilyrth.c",
            "increase hit points": 100,
            "increase spell points": 100,
            "biological": "magical",
        ]),
        "default description": "Crystal droplets suspended in an opalescent liquid that seems to "
            "weep silently within its vial. Distilled from the compassionate "
            "tears of the healing goddess herself, it radiates profound "
            "restorative magic capable of mending both body and spirit.",
        "base experience": 10,
        "default value": 1250,
    ]),
    "tincture of telus":([
        "type": "power",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewEpicPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 12]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/tincture-of-telus.c",
            "biological": "magical",
        ]),
        "default description": "A shimmering amber potion that appears impossibly heavy yet floats "
            "weightlessly within its container. Infused with the essence of "
            "the earth titan Telus, it grants momentary connection to the "
            "fundamental power that shapes mountains and valleys.",
        "base experience": 5,
        "default value": 1500,
    ]),
    "nectar of echlarhol":([
        "type": "power",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewHighElvenPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 15]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/nectar-of-echlarhol.c",
            "increase hit points": 100,
            "increase spell points": 200,
            "biological": "magical",
        ]),
        "default description": "A silvery-blue elixir harvested from moonflowers that bloom once "
            "a century in high elven forests. It glimmers with an inner light "
            "that seems to contain fragments of starlight, and tastes of honey "
            "and distant memories of ancient magic.",
        "base experience": 5,
        "default value": 1750,
    ]),
    "ilaina's elixir":([
        "type": "health",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewElvenPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 15]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/ilainas-elixir.c",
            "increase spell points": 500,
            "biological": "magical",
        ]),
        "default description": "A radiant potion of liquid moonlight and captured whispers of the "
            "elven goddess of magic. The crystalline fluid shifts between "
            "colors with musical tones when disturbed, and drinking it is said "
            "to momentarily reveal the threads of magic binding the world.",
        "base experience": 5,
        "default value": 2000,
    ]),
    "acid resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/acid-resistance.c",
            "biological": "neuroleptic",
        ]),
        "default description": "A viscous yellow-green liquid that causes nearby metals to tarnish "
            "briefly when uncorked. It tastes strongly of lime and limestone, "
            "leaving a chalky coating inside the mouth that shields flesh from "
            "caustic substances.",
        "base experience": 5,
        "default value": 250,
    ]),
    "air resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/air-resistance.c",
            "biological": "neuroleptic",
        ]),
        "default description": "A nearly weightless, cloud-white potion that occasionally releases "
            "tiny whirlwinds when the vial is opened. It tastes of fresh "
            "mountain air and settles into the lungs, allowing the drinker to "
            "withstand even the most punishing winds.",
        "base experience": 5,
        "default value": 250,
    ]),
    "chaos resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/chaos-resistance.c",
            "biological": "neuroleptic",
        ]),
        "default description": "A wild, ever-changing fluid that never settles on a single color "
            "or consistency. Small objects near it temporarily defy gravity, "
            "and drinking it creates a momentary sensation of falling in all "
            "directions at once.",
        "base experience": 5,
        "default value": 250,
    ]),
    "cold resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/cold-resistance.c",
            "biological": "neuroleptic",
        ]),
        "default description": "A steaming blue potion that remains pleasantly warm to the touch "
            "even in freezing temperatures. Frost forms briefly around the "
            "vial but never on it, and drinking it spreads a wave of comforting "
            "warmth through the body.",
        "base experience": 5,
        "default value": 250,
    ]),
    "disease resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/disease-resistance.c",
            "biological": "salicylate",
        ]),
        "default description": "A clear, potent concoction flecked with silver particles that "
            "tingle upon the tongue. It smells of cloves and sweetgrass, and "
            "drinking it causes a momentary fever that quickly subsides, leaving "
            "the body fortified against illness.",
        "base experience": 5,
        "default value": 250,
    ]),
    "earth resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/earth-resistance.c",
            "biological": "neuroleptic",
        ]),
        "default description": "A thick, brown potion that settles like sedimentary layers when "
            "left standing. It smells of rich soil after rain and fills the "
            "drinker with a grounded stability, making their flesh temporarily "
            "resilient as stone.",
        "base experience": 5,
        "default value": 250,
    ]),
    "electricity resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/electricity-resistance.c",
            "biological": "neuroleptic",
        ]),
        "default description": "A vibrant yellow liquid that crackles with tiny sparks and makes "
            "nearby hair stand on end. It tastes sharply of ozone and lemons, "
            "and causes momentary tingling throughout the body as it renders "
            "flesh impervious to electrical harm.",
        "base experience": 5,
        "default value": 250,
    ]),
    "energy resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/energy-resistance.c",
            "biological": "neuroleptic",
        ]),
        "default description": "A pulsing orange potion that seems to absorb light around it, "
            "creating strange shadows even in bright daylight. It tastes of "
            "bitter almonds and cinnamon, and creates a protective aura that "
            "deflects harmful energy forces.",
        "base experience": 5,
        "default value": 250,
    ]),
    "evil resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/evil-resistance.c",
            "biological": "neuroleptic",
        ]),
        "default description": "A radiant white potion with golden streaks that softly illuminate "
            "its container. It smells of frankincense and roses, and drinking "
            "it fills the soul with a sense of peace and clarity that wards "
            "against corruption.",
        "base experience": 5,
        "default value": 250,
    ]),
    "fire resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/fire-resistance.c",
            "biological": "neuroleptic",
        ]),
        "default description": "A deep crimson liquid that remains ice-cold despite its fiery "
            "appearance. Snowflake patterns form briefly on its surface when "
            "agitated, and drinking it creates a cooling sensation that protects "
            "the body from even dragon's flame.",
        "base experience": 5,
        "default value": 250,
    ]),
    "good resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/good-resistance.c",
            "biological": "neuroleptic",
        ]),
        "default description": "A midnight-black potion that absorbs light completely, appearing "
            "as a void within its vial. It smells faintly of grave soil and "
            "tastes of bitter regret, coating the spirit in shadows that repel "
            "even the brightest holy light.",
        "base experience": 5,
        "default value": 250,
    ]),
    "magic resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/magic-resistance.c",
            "biological": "neuroleptic",
        ]),
        "default description": "A silvery-purple liquid that seems to shift and distort the air "
            "around it. Nearby magical effects briefly waver when the vial is "
            "opened, and drinking it renders the body temporarily impervious "
            "to magical manipulation.",
        "base experience": 5,
        "default value": 250,
    ]),
    "neutral resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/neutral-resistance.c",
            "biological": "neuroleptic",
        ]),
        "default description": "A perfectly balanced gray potion that always returns to center when "
            "disturbed. It has no smell and tastes different to each drinker, "
            "creating an aura of perfect neutrality that deflects attacks from "
            "both light and darkness.",
        "base experience": 5,
        "default value": 250,
    ]),
    "paralysis resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/paralysis-resistance.c",
            "biological": "neurotoxin",
        ]),
        "default description": "A quicksilver potion that never stops moving within its container, "
            "constantly swirling with kinetic energy. It tastes of mint and "
            "lightning, sending an electric tingle through the nerves that "
            "preserves freedom of movement.",
        "base experience": 5,
        "default value": 250,
    ]),
    "physical resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/physical-resistance.c",
            "biological": "neuroleptic",
        ]),
        "default description": "A metallic iron-gray potion with the consistency of liquid steel. "
            "It clinks against the vial like solid metal yet pours smoothly, "
            "tasting of blood and iron as it temporarily hardens skin and "
            "muscle against physical blows.",
        "base experience": 5,
        "default value": 250,
    ]),
    "poison resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/poison-resistance.c",
            "biological": "adrenaline",
        ]),
        "default description": "A murky green-black potion flecked with iridescent particles that "
            "sparkle when agitated. It smells deceptively sweet but tastes "
            "incredibly bitter, teaching the body to recognize and reject all "
            "manner of venoms and toxins.",
        "base experience": 5,
        "default value": 250,
    ]),
    "psionic resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/magic-resistance.c",
            "biological": "empathogen",
        ]),
        "default description": "A shimmering indigo potion that creates whispered echoes of "
            "thoughts when unstoppered. It tastes of dreams and forgotten "
            "memories, weaving protective barriers around the mind that shield "
            "against psychic intrusion and assault.",
        "base experience": 5,
        "default value": 250,
    ]),
    "sonic resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/sonic-resistance.c",
            "biological": "neuroleptic",
        ]),
        "default description": "A rippling blue-white potion that completely absorbs all sound in "
            "its immediate vicinity. The vial feels strangely quiet to hold, and "
            "drinking it creates a sensation of perfect silence before rendering "
            "ears resistant to harmful sound.",
        "base experience": 5,
        "default value": 250,
    ]),
    "undead resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/undead-resistance.c",
            "biological": "neuroleptic",
        ]),
        "default description": "A ghostly pale liquid that glows with faint golden radiance in "
            "darkness. It smells of blessed earth and ancient incense, and "
            "drinking it fills the body with vital essence that repels the "
            "corrupting touch of undeath.",
        "base experience": 5,
        "default value": 250,
    ]),
    "water resistance potion":([
        "type": "resistance",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/water-resistance.c",
            "biological": "neuroleptic",
        ]),
        "default description": "A deep blue potion with the curious property of being completely "
            "dry to the touch despite its liquid form. It tastes of salt and "
            "seaweed, creating a hydrophobic barrier around the drinker that "
            "repels water-based attacks.",
        "base experience": 5,
        "default value": 250,
    ]),
    "strength potion":([
        "type": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/strength.c",
            "biological": "steroid",
        ]),
        "default description": "A sanguine red potion with amber sparks that pulse like heartbeats. "
            "It smells of iron and tastes of raw power, causing muscles to "
            "momentarily surge with incredible density and might beyond natural "
            "limitations.",
        "base experience": 5,
        "default value": 750,
    ]),
    "intelligence potion":([
        "type": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/intelligence.c",
            "biological": "magical",
        ]),
        "default description": "A crystalline blue potion with tiny floating symbols that "
            "rearrange themselves into complex patterns when observed. It "
            "tastes of forgotten knowledge and revelation, unlocking mental "
            "pathways normally closed to mortal minds.",
        "base experience": 5,
        "default value": 750,
    ]),
    "dexterity potion":([
        "type": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/dexterity.c",
            "biological": "xanthine",
        ]),
        "default description": "A quicksilver potion that seems to blur with potential movement "
            "even when perfectly still. It tastes of wind and wild berries, "
            "lending preternatural grace and coordination to even the clumsiest "
            "of beings.",
        "base experience": 5,
        "default value": 750,
    ]),
    "wisdom potion":([
        "type": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/wisdom.c",
            "biological": "magical",
        ]),
        "default description": "A milky white potion swirled with opalescent hues that shift with "
            "ancient insight. It smells of old parchment and mountain air, "
            "tasting of experiences not yet lived and bestowing clarity of "
            "perception beyond one's years.",
        "base experience": 5,
        "default value": 750,
    ]),
    "constitution potion":([
        "type": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/constitution.c",
            "biological": "adrenaline",
        ]),
        "default description": "A robust amber potion that pulses with a steady heartbeat rhythm "
            "when held. It smells of mountain stone and tastes of hearty bread "
            "and strong oak, fortifying the body's resilience and endurance "
            "against all manner of hardship.",
        "base experience": 5,
        "default value": 750,
    ]),
    "charisma potion":([
        "type": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/charisma.c",
            "biological": "magical",
        ]),
        "default description": "A shimmering rose-gold potion that catches and enhances all light "
            "around it. It smells of subtle perfume and tastes like honey and "
            "summer wine, enhancing the drinker's natural presence and drawing "
            "others like moths to flame.",
        "base experience": 5,
        "default value": 750,
    ]),
    "speed potion":([
        "type": "combat",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewFortifyingPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/speed.c",
            "biological": "xanthine",
        ]),
        "default description": "A vibrant yellow-orange potion that never stops moving within its "
            "container, constantly whirling with frenetic energy. It tastes of "
            "lightning and citrus, accelerating the body's movements to near "
            "imperceptible speeds.",
        "base experience": 5,
        "default value": 500,
    ]),
    "fortification potion":([
        "type": "combat",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewFortifyingPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/fortification.c",
            "biological": "steroids",
        ]),
        "default description": "A dense iron-gray potion with the consistency of liquid stone. "
            "It clinks against glass as if solid yet pours smoothly, tasting "
            "of mountain granite and steel. The skin visibly hardens and takes "
            "on a subtle metallic sheen after drinking.",
        "base experience": 5,
        "default value": 500,
    ]),
    "tincture of combat prowess":([
        "type": "combat",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/potions/brewFortifyingPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 15]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "/lib/instances/items/potions/traits/tincture-of-combat-prowess.c",
            "biological": "steroids",
       ]),
        "default description": "A crimson potion that pulses with barely contained martial energy. "
            "It smells of battle and iron, and when consumed, causes ancient "
            "combat techniques to flash through the mind while muscles respond "
            "with perfect memory to forgotten training.",
        "base experience": 5,
        "default value": 500,
    ]),
]);

#endif
