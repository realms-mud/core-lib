//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping craftingComponents =
([
    "Type X": ([
        "class": "blade",
        "value": 100,
        "description": "a broad, medium length blade with a lenticular cross-section. "
            "The fuller is wide and runs almost the entire length of the blade, ending in a "
            "sharp, slightly rounded point."
    ]),
    "Type Xa": ([
        "class": "blade",
        "value": 100,
        "description": "a broad, medium length blade with a lenticular cross-section. "
            "The fuller is narrow and runs almost the entire length of the blade, ending in a "
            "acute point."
    ]),
    "Type XI": ([
        "class": "blade",
        "value": 110,
        "description": "a medium length blade with a lenticular cross-section. "
            "The fuller is narrow and runs almost the entire length of the blade, ending in a "
            "sharp, acute point."
    ]),
    "Type XIa": ([
        "class": "blade",
        "value": 115,
        "description": "a broad, evenly tapered tapered, medium length blade with a lenticular cross-section. "
            "The fuller is narrow and runs almost the entire length of the blade, ending in a "
            "sharp, acute point."
    ]),
    "Type XIIa": ([
        "class": "blade",
        "value": 120,
        "description": "a broad, flat, and evenly tapered blade with a lenticular cross-section. "
            "The fuller is narrow and runs 2/3 of the length of the blade, ending in a "
            "sharp, acute point."
    ]),
    "Type XIII": ([
        "class": "blade",
        "value": 110,
        "description": "a broad, flat, blade with parallel edges and a "
            "lenticular cross-section. The fuller is narrow and runs half of "
            "the length of the blade, ending in a rounded point."
    ]),
    "Type XIV": ([
        "class": "blade",
        "value": 105,
        "description": "a broad, flat, sharply tapering blade with a "
            "lenticular cross-section. The fuller is narrow and runs 3/4 of "
            "the length of the blade, ending in a sharp, acute point."
    ]),
    "Type XV": ([
        "class": "blade",
        "value": 125,
        "description": "a broad, sharply tapering blade with a "
            "flattened diamond cross-section and no fuller. "
            "The blade ends in a sharp, acute point."
    ]),
    "Type XVa": ([
        "class": "blade",
        "value": 125,
        "description": "a slender, strongly tapering blade with a "
            "flattened diamond cross-section and no fuller. "
            "The blade ends in a sharp, acute point."
    ]),
    "Type XVI": ([
        "class": "blade",
        "value": 130,
        "description": "a broad, flat, sharply tapering blade with a "
            "flattened diamond cross-section. The fuller is narrow and runs half of "
            "the length of the blade, ending in a sharp, acute point."
    ]),
    "Type XVI": ([
        "class": "blade",
        "value": 135,
        "description": "a broad, slowly tapering blade with a "
            "flattened hexagonal cross-section. The fuller is narrow and runs 1/3 of "
            "the length of the blade, ending in a sharp, acute point."
    ]),
    "Type XVII": ([
        "class": "blade",
        "value": 140,
        "description": "a slender, acutely tapering blade with a "
            "narrow and stout hexagonal cross-section. The fuller is shallow and runs 1/4 of "
            "the length of the blade, ending in a sharp, acute point."
    ]),
    "Type XVIII": ([
        "class": "blade",
        "value": 128,
        "description": "a very broad, gracefully tapering blade with a "
            "flattened diamond cross-section. The fuller is shallow and runs 1/4 of "
            "the length of the blade, ending in a sharp, acute point."
    ]),
    "Type XVIIIa": ([
        "class": "blade",
        "value": 130,
        "description": "a slender, gracefully tapering blade with a "
            "flattened diamond cross-section. The fuller is shallow and runs 1/4 of "
            "the length of the blade, ending in a sharp, acute point."
    ]),
    "Type XVIIIb": ([
        "class": "blade",
        "value": 132,
        "description": "a slender, gracefully tapering blade with a "
            "flattened diamond cross-section. The blade ends in a long, acute "
            "point that has been reinforced."
    ]),
    "Type XVIIIc": ([
        "class": "blade",
        "value": 126,
        "description": "a broad, gracefully tapering blade with a "
            "flattened diamond cross-section. The fuller is shallow and runs 1/4 of "
            "the length of the blade, ending in a long, acute point."
    ]),
    "Type XVIIId": ([
        "class": "blade",
        "value": 125,
        "description": "a slender, acutely tapering blade with a "
            "flattened diamond cross-section. The blade ends in a long, sharp "
            "point that has been reinforced."
    ]),
    "Type XVIIIe": ([
        "class": "blade",
        "value": 140,
        "description": "a long blade with a flattened diamond "
            "cross-section. It has a short ricasso with a narrow fuller in it "
            "and the blade widens at its pronounced mid-rib pronounced mid-rib "
            "before gracefully tapering into a sharp, reinforced point."
    ]),
    "Type XIX": ([
        "class": "blade",
        "value": 135,
        "description": "a long blade with a flattened hexagonal "
            "cross-section with chamfered edges. It has a ricasso with a narrow "
            "fuller running 1/3 of the length of the blade before gracefully "
            "tapering into a spaded point."
    ]),
    "Type XX": ([
        "class": "blade",
        "value": 132,
        "description": "a broad blade with nearly parallel edges that "
            "gracefully taper. It has a flattened octagonal cross-section "
            "with a shallow central fuller running 1/2 the length of the blade "
            "and two shallow parallel fullers running in the upper 1/4 of the "
            "blade which tapers into a spaded point."
    ]),
    "Type XX": ([
        "class": "blade",
        "value": 136,
        "description": "a broad blade with nearly parallel edges that "
            "acutely tapers. It has a flattened hexagonal cross-section "
            "with a shallow central fuller running 1/2 the length of the blade "
            "and two shallow parallel fullers running in the upper 1/4 of the "
            "blade which sharply tapers into an acute point."
    ]),
    "Type XXI": ([
        "class": "blade",
        "value": 135,
        "description": "a broad blade with nearly parallel edges that "
            "acutely tapers. It has a flattened diamond cross-section with "
            "marked edge bevels. It has two shallow parallel fullers running "
            "most of the length of the blade which sharply tapers into an "
            "acute point."
    ]),
    "Type XXII": ([
        "class": "blade",
        "value": 128,
        "description": "a broad, flat blade gracefully tapers. It has "
            "a flattened hexagonal cross-section. It has two deep parallel "
            "fullers running 1/4 of the length of the blade which tapers into an "
            "acute point."
    ]),
    "Flamberge": ([
        "class": "blade",
        "value": 145,
        "description": "a broad, flat, blade with parallel, undulating "
            "edges and a lenticular cross-section. The fuller is narrow and runs "
            "half of the length of the blade, ending in a rounded point."
    ]),
    "Serrated": ([
        "class": "blade",
        "value": 125,
        "description": "a broad, flat, blade with parallel, serrated "
            "edges and a lenticular cross-section. The fuller is narrow and runs "
            "half of the length of the blade, ending in a rounded point."
    ]),
    "Rectangular Bar": ([
        "class": "crossguard",
        "value": 10,
        "description": "a plain, rectangular bar of metal."
    ]),
    "Gaddhjalt": ([
        "class": "crossguard",
        "value": 10,
        "description": "a simple rectangular bar of metal that has been tapered toward each end."
    ]),
    "Waisted": ([
        "class": "crossguard",
        "value": 12,
        "description": "a simple octagonal bar of metal with uniform size at the ends and the tang but has been narrowed or waisted between each end and the tang."
    ]),
    "Bar with Bent Terminals": ([
        "class": "crossguard",
        "value": 15,
        "description": "a simple cylindrical bar of metal that has had its ends bent toward the blade."
    ]),
    "Bow Tie": ([
        "class": "crossguard",
        "value": 15,
        "description": "a bar of metal that has been widened and flattened at its terminals."
    ]),
    "Bent Bow Tie": ([
        "class": "crossguard",
        "value": 18,
        "description": "a bar of metal that has been widened and flattened at its terminals. The terminals are then bent toward the blade."
    ]),
    "Curved": ([
        "class": "crossguard",
        "value": 20,
        "description": "a broad, flat secion of metal that has been curved toward the blade."
    ]),
    "Curved with Knobbed Terminal": ([
        "class": "crossguard",
        "value": 22,
        "description": "a broad, flat secion of metal that has been curved toward the blade. Each terminal has been rolled over into a circular knob."
    ]),
    "Bent Cross with Ecusson": ([
        "class": "crossguard",
        "value": 25,
        "description": "a straight, hexagonal bar with a pronounced ecusson at the tang. The terminals have been bent toward the blade."
    ]),
    "Curved Cross with Ecusson": ([
        "class": "crossguard",
        "value": 30,
        "description": "a straight, flattened-V-shaped bar with a pronounced ecusson at the tang that has been prominently curved toward the blade. Each terminal has been rolled over into a circular knob."
    ]),
    "S-Shaped Cross": ([
        "class": "crossguard",
        "value": 30,
        "description": "a straight, flattened-V-shaped bar with a pronounced ecusson at the tang. Each arm has been strongly curved in the opposite direction along the horizontal plane."
    ]),
    "Swept - Vine Form": ([
        "class": "crossguard",
        "value": 50,
        "description": "an ornate knuckleguard that has been sculpted to appear as though the user's hand has been wrapped in vines."
    ]),
    "Swept": ([
        "class": "crossguard",
        "value": 40,
        "description": "a knuckleguard that has been fashioned to cover a portion of the user's hand."
    ]),
    "Basket": ([
        "class": "crossguard",
        "value": 75,
        "description": "an ornate knuckleguard that has been sculpted to offer significant protection to the user's hand."
    ]),
    "Snake Form": ([
        "class": "crossguard",
        "value": 250,
        "description": "an ornate knuckleguard that has been sculpted to appear as though a snake is protecting the user's hand.",
        "crafting prerequisites": ([
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 2,
        ]),
    ]),
    "Dragon Form": ([
        "class": "crossguard",
        "value": 300,
        "description": "an ornate knuckleguard that has been sculpted to appear as though a dragon is protecting the user's hand.",
        "crafting prerequisites": ([
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
        "crafting materials": ([
            "crystal": 2,
        ]),
    ]),
    "Raven Form": ([
        "class": "crossguard",
        "value": 300,
        "description": "an ornate knuckleguard that has been sculpted to appear as though a raven is protecting the user's hand.",
        "crafting prerequisites": ([
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
        "crafting materials": ([
            "crystal": 2,
        ]),
    ]),
    "Eagle Form": ([
        "class": "crossguard",
        "value": 300,
        "description": "an ornate knuckleguard that has been sculpted to appear as though an eagle is protecting the user's hand.",
        "crafting prerequisites": ([
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
        "crafting materials": ([
            "crystal": 2,
        ]),
    ]),
    "Hawk Form": ([
        "class": "crossguard",
        "value": 300,
        "description": "an ornate knuckleguard that has been sculpted to appear as though a hawk is protecting the user's hand.",
        "crafting prerequisites": ([
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
        "crafting materials": ([
            "crystal": 2,
        ]),
    ]),
    "Griffin Form": ([
        "class": "crossguard",
        "value": 300,
        "description": "an ornate knuckleguard that has been sculpted to appear as though a griffin is protecting the user's hand.",
        "crafting prerequisites": ([
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
        "crafting materials": ([
            "crystal": 2,
        ]),
    ]),
    "Dracolich Form": ([
        "class": "crossguard",
        "value": 325,
        "description": "an ornate knuckleguard that has been sculpted to appear as though a dracolich is protecting the user's hand.",
        "crafting prerequisites": ([
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 15]),
        ]),
        "crafting materials": ([
            "crystal": 2,
        ]),
    ]),
    "Skeleton Form": ([
        "class": "crossguard",
        "value": 300,
        "description": "an ornate knuckleguard that has been sculpted to appear as though a human skeleton is protecting the user's hand.",
        "crafting prerequisites": ([
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 15]),
        ]),
        "crafting materials": ([
            "crystal": 2,
        ]),
    ]),
]);
