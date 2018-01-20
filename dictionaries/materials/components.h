//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping craftingComponents =
([
    "Type X": ([
        "class": "blade",
        "value": 100,
        "description": "a broad, medium length metal blade with a lenticular cross-section. "
            "The fuller is wide and runs almost the entire length of the blade, ending in a "
            "sharp, slightly rounded point."
    ]),
    "Type Xa": ([
        "class": "blade",
        "value": 100,
        "description": "a broad, medium length metal blade with a lenticular cross-section. "
            "The fuller is narrow and runs almost the entire length of the blade, ending in a "
            "acute point."
    ]),
    "Type XI": ([
        "class": "blade",
        "value": 110,
        "description": "a medium length metal blade with a lenticular cross-section. "
            "The fuller is narrow and runs almost the entire length of the blade, ending in a "
            "sharp, acute point."
    ]),
    "Type XIa": ([
        "class": "blade",
        "value": 115,
        "description": "a broad, evenly tapered tapered, medium length metal blade with a lenticular cross-section. "
            "The fuller is narrow and runs almost the entire length of the blade, ending in a "
            "sharp, acute point."
    ]),
    "Type XIIa": ([
        "class": "blade",
        "value": 120,
        "description": "a broad, flat, and evenly tapered metal blade with a lenticular cross-section. "
            "The fuller is narrow and runs 2/3 of the length of the blade, ending in a "
            "sharp, acute point."
    ]),
    "Type XIII": ([
        "class": "blade",
        "value": 110,
        "description": "a broad, flat, metal blade with parallel edges and a "
            "lenticular cross-section. The fuller is narrow and runs half of "
            "the length of the blade, ending in a rounded point."
    ]),
    "Type XIV": ([
        "class": "blade",
        "value": 105,
        "description": "a broad, flat, sharply tapering metal blade with a "
            "lenticular cross-section. The fuller is narrow and runs 3/4 of "
            "the length of the blade, ending in a sharp, acute point."
    ]),
    "Type XV": ([
        "class": "blade",
        "value": 125,
        "description": "a broad, sharply tapering metal blade with a "
            "flattened diamond cross-section and no fuller. "
            "The blade ends in a sharp, acute point."
    ]),
    "Type XVa": ([
        "class": "blade",
        "value": 125,
        "description": "a slender, strongly tapering metal blade with a "
            "flattened diamond cross-section and no fuller. "
            "The blade ends in a sharp, acute point."
    ]),
    "Type XVI": ([
        "class": "blade",
        "value": 130,
        "description": "a broad, flat, sharply tapering metal blade with a "
            "flattened diamond cross-section. The fuller is narrow and runs half of "
            "the length of the blade, ending in a sharp, acute point."
    ]),
    "Type XVI": ([
        "class": "blade",
        "value": 135,
        "description": "a broad, slowly tapering metal blade with a "
            "flattened hexagonal cross-section. The fuller is narrow and runs 1/3 of "
            "the length of the blade, ending in a sharp, acute point."
    ]),
    "Type XVII": ([
        "class": "blade",
        "value": 140,
        "description": "a slender, acutely tapering metal blade with a "
            "narrow and stout hexagonal cross-section. The fuller is shallow and runs 1/4 of "
            "the length of the blade, ending in a sharp, acute point."
    ]),
    "Type XVIII": ([
        "class": "blade",
        "value": 128,
        "description": "a very broad, gracefully tapering metal blade with a "
            "flattened diamond cross-section. The fuller is shallow and runs 1/4 of "
            "the length of the blade, ending in a sharp, acute point."
    ]),
    "Type XVIIIa": ([
        "class": "blade",
        "value": 130,
        "description": "a slender, gracefully tapering metal blade with a "
            "flattened diamond cross-section. The fuller is shallow and runs 1/4 of "
            "the length of the blade, ending in a sharp, acute point."
    ]),
    "Type XVIIIb": ([
        "class": "blade",
        "value": 132,
        "description": "a slender, gracefully tapering metal blade with a "
            "flattened diamond cross-section. The blade ends in a long, acute "
            "point that has been reinforced."
    ]),
    "Type XVIIIc": ([
        "class": "blade",
        "value": 126,
        "description": "a broad, gracefully tapering metal blade with a "
            "flattened diamond cross-section. The fuller is shallow and runs 1/4 of "
            "the length of the blade, ending in a long, acute point."
    ]),
    "Type XVIIId": ([
        "class": "blade",
        "value": 125,
        "description": "a slender, acutely tapering metal blade with a "
            "flattened diamond cross-section. The blade ends in a long, sharp "
            "point that has been reinforced."
    ]),
    "Type XVIIIe": ([
        "class": "blade",
        "value": 140,
        "description": "a long metal blade with a flattened diamond "
            "cross-section. It has a short ricasso with a narrow fuller in it "
            "and the blade widens at its pronounced mid-rib pronounced mid-rib "
            "before gracefully tapering into a sharp, reinforced point."
    ]),
    "Type XIX": ([
        "class": "blade",
        "value": 135,
        "description": "a long metal blade with a flattened hexagonal "
            "cross-section with chamfered edges. It has a ricasso with a narrow "
            "fuller running 1/3 of the length of the blade before gracefully "
            "tapering into a spaded point."
    ]),
    "Type XX": ([
        "class": "blade",
        "value": 132,
        "description": "a broad metal blade with nearly parallel edges that "
            "gracefully taper. It has a flattened octagonal cross-section "
            "with a shallow central fuller running 1/2 the length of the blade "
            "and two shallow parallel fullers running in the upper 1/4 of the "
            "blade which tapers into a spaded point."
    ]),
    "Type XX": ([
        "class": "blade",
        "value": 136,
        "description": "a broad metal blade with nearly parallel edges that "
            "acutely tapers. It has a flattened hexagonal cross-section "
            "with a shallow central fuller running 1/2 the length of the blade "
            "and two shallow parallel fullers running in the upper 1/4 of the "
            "blade which sharply tapers into an acute point."
    ]),
    "Type XXI": ([
        "class": "blade",
        "value": 135,
        "description": "a broad metal blade with nearly parallel edges that "
            "acutely tapers. It has a flattened diamond cross-section with "
            "marked edge bevels. It has two shallow parallel fullers running "
            "most of the length of the blade which sharply tapers into an "
            "acute point."
    ]),
    "Type XXII": ([
        "class": "blade",
        "value": 128,
        "description": "a broad, flat metal blade gracefully tapers. It has "
            "a flattened hexagonal cross-section. It has two deep parallel "
            "fullers running 1/4 of the length of the blade which tapers into an "
            "acute point."
    ]),
    "Flamberge": ([
        "class": "blade",
        "value": 145,
        "description": "a broad, flat, metal blade with parallel, undulating "
            "edges and a lenticular cross-section. The fuller is narrow and runs "
            "half of the length of the blade, ending in a rounded point."
    ]),
    "Serrated": ([
        "class": "blade",
        "value": 125,
        "description": "a broad, flat, metal blade with parallel, serrated "
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
        "description": "an ornate metal knuckleguard that has been sculpted to appear as though a snake with crystal eyes is protecting the user's hand.",
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
        "description": "an ornate metal knuckleguard that has been sculpted to appear as though a dragon with crystal eyes is protecting the user's hand.",
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
        "description": "an ornate metal knuckleguard that has been sculpted to appear as though a raven with crystal eyes is protecting the user's hand.",
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
        "description": "an ornate metal knuckleguard that has been sculpted to appear as though an eagle with crystal eyes is protecting the user's hand.",
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
        "description": "an ornate metal knuckleguard that has been sculpted to appear as though a hawk with crystal eyes is protecting the user's hand.",
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
        "description": "an ornate metal knuckleguard that has been sculpted to appear as though a griffin with crystal eyes is protecting the user's hand.",
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
        "description": "an ornate metal knuckleguard that has been sculpted to appear as though a dracolich with crystal eyes is protecting the user's hand.",
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
        "description": "an ornate metal knuckleguard that has been sculpted to appear as though a human skeleton with crystal eyes is protecting the user's hand.",
        "crafting prerequisites": ([
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 15]),
        ]),
        "crafting materials": ([
            "crystal": 2,
        ]),
    ]),
    "Tapered Grip": ([
        "class": "hilt",
        "value": 10,
        "description": "a simple metal hilt covered with a tapered grip made out of wood and wrapped in leather."
    ]),
    "Ovular Grip": ([
        "class": "hilt",
        "value": 10,
        "description": "a simple metal hilt covered with a grip made out of wood and wrapped in leather that gently curves in at the two ends."
    ]),
    "Cylindrical Grip": ([
        "class": "hilt",
        "value": 5,
        "description": "a simple metal hilt covered with a grip made out of wood and wrapped in leather."
    ]),
    "Lattice Grip": ([
        "class": "hilt",
        "value": 15,
        "description": "a hilt of metal covered with a grip made out of wood and wrapped in latticed leather."
    ]),
    "Helix Grip": ([
        "class": "hilt",
        "value": 15,
        "description": "a hilt of metal covered with a slightly ovular grip made out of wood and wrapped in leather. The leather has a helix of metal wire wrapped around it."
    ]),
    "Rope Grip": ([
        "class": "hilt",
        "value": 10,
        "description": "a hilt of metal covered with a slightly ovular grip made out of wood and wrapped in thin strands of leather."
    ]),
    "Spiral Grip": ([
        "class": "hilt",
        "value": 15,
        "description": "a hilt of metal covered with a slightly ovular grip made out of wood and wrapped in spiraled metal wire."
    ]),
    "Brazil-nut": ([
        "class": "pommel",
        "value": 15,
        "description": "a wide metal pommel with a single lobes, giving it a shape somewhat like a Brazil-nut."
    ]),
    "Mushroom": ([
        "class": "pommel",
        "value": 15,
        "description": "a sturdy metal pommel with a short, rounded end."
    ]),
    "Carolingian": ([
        "class": "pommel",
        "value": 15,
        "description": "a wide metal pommel with several lobes, giving it the shape of a 'cocked hat'."
    ]),
    "Lobed": ([
        "class": "pommel",
        "value": 15,
        "description": "a wide, heavy metal pommel with several lobes, giving it the shape of a 'cocked hat'."
    ]),
    "Shell": ([
        "class": "pommel",
        "value": 15,
        "description": "a wide, heavy metal pommel shaped somewhat like a clam shell, tapering at the tip."
    ]),
    "Angular Shell": ([
        "class": "pommel",
        "value": 15,
        "description": "a thin metal pommel with a pentagonal shape."
    ]),
    "Concave Disk": ([
        "class": "pommel",
        "value": 15,
        "description": "a disc-shaped metal pommel with thick, concave faces."
    ]),
    "Convex Disk": ([
        "class": "pommel",
        "value": 25,
        "description": "a disc-shaped metal pommel with thick, squashed globular form and flower-like pattern on its surface."
    ]),
    "Chamfered Disk": ([
        "class": "pommel",
        "value": 18,
        "description": "a thick disc-shaped metal pommel with thick, chamfered edges."
    ]),
    "Broad Chamfer": ([
        "class": "pommel",
        "value": 20,
        "description": "a thick disc-shaped metal pommel with thick chamfered edge that widens to the radius of the pommel."
    ]),
    "Multi-disc": ([
        "class": "pommel",
        "value": 20,
        "description": "a thick metal pommel fashioned of two discs - a flatter outer disc and a raised inner disc."
    ]),
    "Boat": ([
        "class": "pommel",
        "value": 20,
        "description": "a thick metal pommel shaped somewhat like a boat."
    ]),
    "Crescent": ([
        "class": "pommel",
        "value": 20,
        "description": "a sturdy metal pommel shaped like a crescent, the outer curve away from the blade."
    ]),
    "Shield": ([
        "class": "pommel",
        "value": 18,
        "description": "a wide metal pommel shaped somewhat like a shield."
    ]),
    "Sphere": ([
        "class": "pommel",
        "value": 15,
        "description": "a solid metal pommel of spherical shape."
    ]),
    "Faceted": ([
        "class": "pommel",
        "value": 15,
        "description": "a solid metal pommel with a faceted shape. It is wide at the end and tapers toward the grip."
    ]),
    "Fish Tail": ([
        "class": "pommel",
        "value": 15,
        "description": "a metal pommel with a with a somewhat fish-tailed shape."
    ]),
    "Eagle Talon": ([
        "class": "pommel",
        "value": 50,
        "description": "a broad metal pommel that has been intricately sculpted to resemble an eagle's talon. Clutched in its grip is a beautifully cut crystal.",
        "crafting prerequisites": ([
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 1,
        ]),
    ]),
    "Dragon Talon": ([
        "class": "pommel",
        "value": 50,
        "description": "an exquisite metal pommel that has been intricately sculpted to resemble a dragon's talon. Clutched in its grip is a beautifully cut crystal.",
        "crafting prerequisites": ([
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 1,
        ]),
    ]),
    "Griffin Talon": ([
        "class": "pommel",
        "value": 50,
        "description": "an exquisite metal pommel that has been intricately sculpted to resemble a griffin's talon. Clutched in its grip is a gemstone.",
        "crafting prerequisites": ([
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 1,
        ]),
    ]),
    "Wolf Maw": ([
        "class": "pommel",
        "value": 50,
        "description": "an exquisite metal pommel that has been intricately sculpted to resemble a wolf's head. It has two small crystal eyes.",
        "crafting prerequisites": ([
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 1,
        ]),
    ]),
    "Feline": ([
        "class": "pommel",
        "value": 50,
        "description": "an exquisite metal pommel that has been intricately sculpted to resemble a cat's head. It has two small crystal eyes.",
        "crafting prerequisites": ([
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 1,
        ]),
    ]),
    "Dragon Maw": ([
        "class": "pommel",
        "value": 50,
        "description": "an exquisite metal pommel that has been intricately sculpted to resemble a dragon's head. It has two small crystal eyes.",
        "crafting prerequisites": ([
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 1,
        ]),
    ]),
    "Serpent": ([
        "class": "pommel",
        "value": 50,
        "description": "an exquisite metal pommel that has been intricately sculpted to resemble a snake's head. It has two small crystal eyes.",
        "crafting prerequisites": ([
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 1,
        ]),
    ]),
    "Simple binding": ([
        "class": "binding",
        "value": 0,
        "description": "a simple leather strap."
    ]),
    "Glove": ([
        "class": "binding",
        "value": 20,
        "description": "a leather glove that cunningly houses the weapon's blades."
    ]),
    "Retracting Glove": ([
        "class": "binding",
        "value": 100,
        "description": "a leather glove that cunningly houses the weapon's blades. It contains a mechanism that allows the claws to be retracted when not in use."
    ]),
    "Simple shaft": ([
        "class": "shaft",
        "value": 5,
        "description": "a simple, straight pole of wood with leather wrapped around the grip."
    ]),
    "Segmented shaft": ([
        "class": "shaft",
        "value": 15,
        "description": "a simple, pole of wood with slightly wider segments of wood at the quarter and mid points. Leather has been wrapped around the grip."
    ]),
    "Knotwork shaft": ([
        "class": "shaft",
        "value": 50,
        "description": "a pole of wood that has exquisitely carved knotwork along its length. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
    ]),
    "Serpent shaft": ([
        "class": "shaft",
        "value": 70,
        "description": "a pole of wood that has exquisitely carved scales along its length and a carved serpent's head about two-thirds of the way up its length. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Dragon shaft": ([
        "class": "shaft",
        "value": 70,
        "description": "a pole of wood that has been exquisitely carved with a scene of intertwined dragons along its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Huntsman's shaft": ([
        "class": "shaft",
        "value": 70,
        "description": "a pole of wood that has been exquisitely carved with a scene of a hunter stalking a boar in a forest. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Griffin shaft": ([
        "class": "shaft",
        "value": 70,
        "description": "a pole of wood that has been exquisitely carved with a scene of intertwined griffins along its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Eagle shaft": ([
        "class": "shaft",
        "value": 70,
        "description": "a pole of wood that has been exquisitely carved with a scene of many eagles in flight along its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Raven shaft": ([
        "class": "shaft",
        "value": 70,
        "description": "a pole of wood that has been exquisitely carved with a scene of many ravens in flight along its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Vine shaft": ([
        "class": "shaft",
        "value": 70,
        "description": "a pole of wood that has been exquisitely carved with a scene of intertwined vines along its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Runed shaft": ([
        "class": "shaft",
        "value": 70,
        "description": "a pole of wood that has been exquisitely carved with runes of power along its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Skeleton shaft": ([
        "class": "shaft",
        "value": 70,
        "description": "a pole of wood that has been exquisitely carved with a macabre scene of intertwined skeletons along its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Dracolich shaft": ([
        "class": "shaft",
        "value": 70,
        "description": "a pole of wood that has a hideously carved scene of skeletal dragons along its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Wrath shaft": ([
        "class": "shaft",
        "value": 70,
        "description": "a pole of wood that has a terrifying carved scene of a brutal battle its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Simple Staff Head": ([
        "class": "staff head",
        "value": 5,
        "description": "a simple wood cap placed on the end."
    ]),
    "Knotwork Head": ([
        "class": "staff head",
        "value": 15,
        "description": "a slightly bulbous head of wood that has intricate knotwork carved into it.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 2]),
            "sculpture": (["type":"skill", "value": 2]),
        ]),
    ]),
    "Serpent Head": ([
        "class": "staff head",
        "value": 75,
        "description": "a slightly bulbous head of wood that has been intricately carved into the shape of a serpent's head. The serpent has eyes of encrusted crystal.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 1,
        ]),
    ]),
    "Dragon Head": ([
        "class": "staff head",
        "value": 75,
        "description": "a slightly bulbous head of wood that has been intricately carved into the shape of a dragon's head. The dragon has eyes of encrusted crystal.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 1,
        ]),
    ]),
    "Griffin Head": ([
        "class": "staff head",
        "value": 75,
        "description": "a slightly bulbous head of wood that has been intricately carved into the shape of a griffin's head. The griffin has eyes of encrusted crystal.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 1,
        ]),
    ]),
    "Eagle Head": ([
        "class": "staff head",
        "value": 75,
        "description": "a slightly bulbous head of wood that has been intricately carved into the shape of an eagle's head. The eagle has eyes of encrusted crystal.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 1,
        ]),
    ]),
    "Raven Head": ([
        "class": "staff head",
        "value": 75,
        "description": "a slightly bulbous head of wood that has been intricately carved into the shape of a raven's head. The raven has eyes of encrusted crystal.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 1,
        ]),
    ]),
    "Wolf Head": ([
        "class": "staff head",
        "value": 75,
        "description": "a slightly bulbous head of wood that has been intricately carved into the shape of a wolf's head. The wolf has eyes of encrusted crystal.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 1,
        ]),
    ]),
    "Skull Head": ([
        "class": "staff head",
        "value": 75,
        "description": "a slightly bulbous head of wood that has been intricately carved into the shape of a human skull. The skull has eyes of encrusted crystal.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "gem crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 1,
        ]),
    ]),
    "Eagle Talon Head": ([
        "class": "staff head",
        "value": 175,
        "description": "a slightly bulbous head of wood that has been intricately carved into the shape of an eagle's talon embossed with metal. It is clutching a large crystal.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "gem crafting": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 10]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 1,
            "metal": 1,
        ]),
    ]),
    "Crystal Head": ([
        "class": "staff head",
        "value": 175,
        "description": "a slightly bulbous head of wood that has been intricately carved into the shape of vines of wood and metal wrapped around a large crystal.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "gem crafting": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 10]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 1,
            "metal": 1,
        ]),
    ]),
    "Celestial Head": ([
        "class": "staff head",
        "value": 175,
        "description": "a slightly bulbous head of metal that has been intricately carved into a stylized orb of crystal wrapped in wood and metal.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "gem crafting": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 10]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "crystal": 1,
            "metal": 1,
        ]),
    ]),
]);
