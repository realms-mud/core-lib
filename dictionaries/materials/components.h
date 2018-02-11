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
    "Tapered Hilt": ([
        "class": "hilt",
        "value": 10,
        "description": "a simple metal hilt covered with a tapered grip made out of wood and wrapped in leather."
    ]),
    "Ovular Hilt": ([
        "class": "hilt",
        "value": 10,
        "description": "a simple metal hilt covered with a grip made out of wood and wrapped in leather that gently curves in at the two ends."
    ]),
    "Cylindrical Hilt": ([
        "class": "hilt",
        "value": 5,
        "description": "a simple metal hilt covered with a grip made out of wood and wrapped in leather."
    ]),
    "Lattice Hilt": ([
        "class": "hilt",
        "value": 15,
        "description": "a hilt of metal covered with a grip made out of wood and wrapped in latticed leather."
    ]),
    "Helix Hilt": ([
        "class": "hilt",
        "value": 15,
        "description": "a hilt of metal covered with a slightly ovular grip made out of wood and wrapped in leather. The leather has a helix of metal wire wrapped around it."
    ]),
    "Rope Hilt": ([
        "class": "hilt",
        "value": 10,
        "description": "a hilt of metal covered with a slightly ovular grip made out of wood and wrapped in thin strands of leather."
    ]),
    "Spiral Hilt": ([
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
        "description": "a pommel of metal with a with a somewhat fish-tailed shape."
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
    "Simple haft": ([
        "class": "haft",
        "value": 5,
        "description": "a simple, straight roughly three foot long handle of wood with leather wrapped around the grip."
    ]),
    "Segmented haft": ([
        "class": "haft",
        "value": 15,
        "description": "a simple, roughly three foot long handle of wood with slightly wider segments of wood at the quarter and mid points. Leather has been wrapped around the grip."
    ]),
    "Knotwork haft": ([
        "class": "haft",
        "value": 50,
        "description": "a roughly three foot long handle of wood that has exquisitely carved knotwork along its length. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 5]),
        ]),
    ]),
    "Serpent haft": ([
        "class": "haft",
        "value": 70,
        "description": "a roughly three foot long handle of wood that has exquisitely carved scales along its length and a carved serpent's head about two-thirds of the way up its length. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Dragon haft": ([
        "class": "haft",
        "value": 70,
        "description": "a roughly three foot long handle of wood that has been exquisitely carved with a scene of intertwined dragons along its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Huntsman's haft": ([
        "class": "haft",
        "value": 70,
        "description": "a roughly three foot long handle of wood that has been exquisitely carved with a scene of a hunter stalking a boar in a forest. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Griffin haft": ([
        "class": "haft",
        "value": 70,
        "description": "a roughly three foot long handle of wood that has been exquisitely carved with a scene of intertwined griffins along its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Eagle haft": ([
        "class": "haft",
        "value": 70,
        "description": "a roughly three foot long handle of wood that has been exquisitely carved with a scene of many eagles in flight along its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Raven haft": ([
        "class": "haft",
        "value": 70,
        "description": "a roughly three foot long handle of wood that has been exquisitely carved with a scene of many ravens in flight along its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Vine haft": ([
        "class": "haft",
        "value": 70,
        "description": "a roughly three foot long handle of wood that has been exquisitely carved with a scene of intertwined vines along its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Runed haft": ([
        "class": "haft",
        "value": 70,
        "description": "a roughly three foot long handle of wood that has been exquisitely carved with runes of power along its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Skeleton haft": ([
        "class": "haft",
        "value": 70,
        "description": "a roughly three foot long handle of wood that has been exquisitely carved with a macabre scene of intertwined skeletons along its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Dracolich haft": ([
        "class": "haft",
        "value": 70,
        "description": "a roughly three foot long handle of wood that has a hideously carved scene of skeletal dragons along its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Wrath haft": ([
        "class": "haft",
        "value": 70,
        "description": "a roughly three foot long handle of wood that has a terrifying carved scene of a brutal battle its course. Etched leather has been wrapped around it in two locations for improved grip.",
        "crafting prerequisites": ([
            "wood crafting": (["type":"skill", "value": 5]),
            "sculpture": (["type":"skill", "value": 10]),
        ]),
    ]),
    "Tapered Grip": ([
        "class": "grip",
        "value": 10,
        "description": "a simple leather grip wraps around a a tapered haft."
    ]),
    "Ovular Grip": ([
        "class": "grip",
        "value": 10,
        "description": "a grip wrapped in leather that gently curves in at the two ends."
    ]),
    "Cylindrical Grip": ([
        "class": "grip",
        "value": 5,
        "description": "a simple grip wrapped in leather."
    ]),
    "Lattice Grip": ([
        "class": "grip",
        "value": 15,
        "description": "a grip wrapped in latticed leather."
    ]),
    "Helix Grip": ([
        "class": "grip",
        "value": 15,
        "description": "a slightly ovular grip wrapped in leather. The leather has a helix of metal wire wrapped around it."
    ]),
    "Rope Grip": ([
        "class": "grip",
        "value": 10,
        "description": "a slightly ovular grip wrapped in thin strands of leather."
    ]),
    "Spiral Grip": ([
        "class": "grip",
        "value": 15,
        "description": "a slightly ovular grip made out of wood and wrapped in spiraled metal wire."
    ]),
    "Type A": ([
        "class": "axe head",
        "value": 15,
        "description": "a narrow metal head with a crescent cutting edge and a symmetrical concave top and bottom. Both the top and bottom lugs are fairly subtle."
    ]),
    "Type B": ([
        "class": "axe head",
        "value": 25,
        "description": "a narrow metal head with a crescent cutting edge that ends in a large beard. It has a symmetrical concave bit. Both the top and bottom lugs are fairly subtle."
    ]),
    "Type B-a": ([
        "class": "axe head",
        "value": 50,
        "description": "a narrow metal head with a crescent cutting edge that ends in a large beard. It has a symmetrical concave bit. Both the top and bottom lugs are fairly subtle. On the axe's butt is a rather large fluke."
    ]),
    "Type C": ([
        "class": "axe head",
        "value": 25,
        "description": "a narrow metal head with a crescent cutting edge that ends in a large beard. It has a bit with a straight top and a concave bottom. There are no top lugs and the bottom ones are fairly subtle."
    ]),
    "Type C-a": ([
        "class": "axe head",
        "value": 50,
        "description": "a narrow metal head with a crescent cutting edge that ends in a large beard. It has a bit with a straight top and a concave bottom. There are no top lugs and the bottom ones are fairly subtle. On the axe's butt is a rather large fluke."
    ]),
    "Type D": ([
        "class": "axe head",
        "value": 25,
        "description": "a head of metal with a straight cutting edge that ends in a subtle beard. It has an asymmetrical concave bit. Both the top and bottom lugs are pronounced."
    ]),
    "Type D-a": ([
        "class": "axe head",
        "value": 25,
        "description": "a head of metal with a straight cutting edge that ends in a subtle beard. It has an asymmetrical concave bit. Both the top and bottom lugs are pronounced. On the axe's butt is a rather large fluke."
    ]),
    "Type E": ([
        "class": "axe head",
        "value": 25,
        "description": "a head of metal with a crescent cutting edge with a rather pronounced upper edge and a cropped beard on the bottom. It has an asymmetrical concave bit. Both the top and bottom lugs are pronounced."
    ]),
    "Type F": ([
        "class": "axe head",
        "value": 30,
        "description": "a head of metal with a crescent cutting edge with a gracefully angled upper edge and a cropped beard on the bottom. It has a slightly asymmetrical concave bit. Both the top and bottom lugs are pronounced."
    ]),
    "Type F-a": ([
        "class": "axe head",
        "value": 55,
        "description": "a head of metal with a crescent cutting edge with a gracefully angled upper edge and a cropped beard on the bottom. It has a slightly asymmetrical concave bit. Both the top and bottom lugs are pronounced. On the axe's butt is a rather large fluke."
    ]),
    "Type G": ([
        "class": "axe head",
        "value": 20,
        "description": "a narrow metal head with a crescent cutting edge and a symmetrical concave top and bottom. Both the top and bottom lugs are rather pronounced."
    ]),
    "Type H": ([
        "class": "axe head",
        "value": 20,
        "description": "a narrow metal head with a crescent cutting edge and a symmetrical concave top and bottom. Both the top and bottom lugs are asymmetric and rather pronounced."
    ]),
    "Type I": ([
        "class": "axe head",
        "value": 20,
        "description": "a rather thick metal head with a crescent cutting edge and a symmetrical concave top and bottom. Both the top and bottom lugs are rather pronounced."
    ]),
    "Type K": ([
        "class": "axe head",
        "value": 45,
        "description": "a broad metal head with a crescent cutting edge and a symmetrical concave top and bottom. Both the top and bottom lugs are asymmetric and rather pronounced."
    ]),
    "Type L": ([
        "class": "axe head",
        "value": 30,
        "description": "a head of metal with a large crescent cutting edge. The top of the cutting edge is angled somewhat forward from the bottom of the edge. It has a slightly asymmetrical concave bit. Both the top and bottom lugs are pronounced."
    ]),
    "Type L-a": ([
        "class": "axe head",
        "value": 30,
        "description": "a head of metal with a large crescent cutting edge. The top of the cutting edge is angled somewhat forward from the bottom of the edge. It has a slightly asymmetrical concave bit. Both the top and bottom lugs are pronounced. On the axe's butt is a rather large fluke."
    ]),
    "Type M": ([
        "class": "axe head",
        "value": 45,
        "description": "a head of metal with an extremely broad crescent cutting edge and a symmetrical concave top and bottom. Both the top and bottom lugs are asymmetric and rather pronounced."
    ]),
    "Type M-a": ([
        "class": "axe head",
        "value": 75,
        "description": "a head of metal with an extremely broad crescent cutting edge and a symmetrical concave top and bottom. Both the top and bottom lugs are asymmetric and rather pronounced. On the axe's butt is a rather large fluke."
    ]),
    "Type A-d": ([
        "class": "double axe head",
        "value": 30,
        "description": "a narrow metal head with a pair of counter-balanced, crescent cutting edges and symmetrical concave tops and bottoms. Both the top and bottom lugs are fairly subtle."
    ]),
    "Type B-d": ([
        "class": "double axe head",
        "value": 50,
        "description": "a narrow metal head with a pair of counter-balanced, crescent cutting edges that ends in large beards. It has a symmetrical concave bit. Both the top and bottom lugs are fairly subtle."
    ]),
    "Type C-d": ([
        "class": "double axe head",
        "value": 50,
        "description": "a narrow metal head with a pair of counter-balanced, crescent cutting edges that end in large beards. It has a bit with a straight top and a concave bottom. There are no top lugs and the bottom ones are fairly subtle."
    ]),
    "Type D-d": ([
        "class": "double axe head",
        "value": 50,
        "description": "a head of metal with a pair of counter-balanced, straight cutting edges that end in subtle beards. It has an asymmetrical concave bit. Both the top and bottom lugs are pronounced."
    ]),
    "Type E-d": ([
        "class": "double axe head",
        "value": 50,
        "description": "a head of metal with a pair of counter-balanced, crescent cutting edges with rather pronounced upper edges and cropped beards on the bottom. It has an asymmetrical concave bit. Both the top and bottom lugs are pronounced."
    ]),
    "Type F-d": ([
        "class": "double axe head",
        "value": 60,
        "description": "a head of metal with a pair of counter-balanced, crescent cutting edges with a gracefully angled upper edge and a cropped beard on the bottom. It has a slightly asymmetrical concave bit. Both the top and bottom lugs are pronounced."
    ]),
    "Type G-d": ([
        "class": "double axe head",
        "value": 40,
        "description": "a narrow metal head with a pair of counter-balanced, crescent cutting edges and symmetrical concave tops and bottoms. Both the top and bottom lugs are rather pronounced."
    ]),
    "Type H-d": ([
        "class": "double axe head",
        "value": 40,
        "description": "a narrow metal head with a pair of counter-balanced, crescent cutting edges and symmetrical concave tops and bottoms. Both the top and bottom lugs are asymmetric and rather pronounced."
    ]),
    "Type I-d": ([
        "class": "double axe head",
        "value": 40,
        "description": "a rather thick metal head with a pair of counter-balanced, crescent cutting edges and symmetrical concave tops and bottoms. Both the top and bottom lugs are rather pronounced."
    ]),
    "Type K-d": ([
        "class": "double axe head",
        "value": 90,
        "description": "a broad metal head with a pair of counter-balanced, crescent cutting edges and symmetrical concave tops and bottoms. Both the top and bottom lugs are asymmetric and rather pronounced."
    ]),
    "Type L-d": ([
        "class": "double axe head",
        "value": 60,
        "description": "a head of metal with a pair of counter-balanced, large crescent cutting edges. The top of the cutting edges are angled somewhat forward from the bottom of the edge. It has a slightly asymmetrical concave bit. Both the top and bottom lugs are pronounced."
    ]),
    "Type M-d": ([
        "class": "double axe head",
        "value": 90,
        "description": "a head of metal with a pair of counter-balanced, extremely broad crescent cutting edges and symmetrical concave tops and bottoms. Both the top and bottom lugs are asymmetric and rather pronounced."
    ]),
    "Triangular tip": ([
        "class": "panabas head",
        "value": 60,
        "description": "a head of metal with a gracefully arcing cutting edge that ends in a sharp point. The tip then angles backward into a broad, triangular spike that ends in a concave cutting edge."
    ]),
    "Flattened tip": ([
        "class": "panabas head",
        "value": 50,
        "description": "a head of metal with a gracefully arcing cutting edge that ends in a flattened end. The reverse side angles backward into a concave cutting edge."
    ]),
    "Rounded tip": ([
        "class": "panabas head",
        "value": 45,
        "description": "a curved, broad metal blade with nearly parallel edges that "
            "first widen before gracefully tapering into a rounded point."
    ]),
    "Pointed tip": ([
        "class": "panabas head",
        "value": 75,
        "description": "a curved, broad metal blade with nearly parallel edges that "
            "has a pronounced bend in the blade where it widens before gracefully tapering into an acute point."
    ]),
    "Simple Hammer": ([
        "class": "hammer head",
        "value": 10,
        "description": "a large, rounded metal head with a broad, flat surface."
    ]),
    "Simple Fluked Hammer": ([
        "class": "hammer head",
        "value": 20,
        "description": "a large, rounded metal head with a broad, flat surface. It is balanced with a sharp fluke on the opposite side of the hammer surface."
    ]),
    "Cubic Hammer": ([
        "class": "hammer head",
        "value": 15,
        "description": "a large, square metal head with a broad, flat surface."
    ]),
    "Cubic Fluked Hammer": ([
        "class": "hammer head",
        "value": 25,
        "description": "a large, square metal head with a broad, flat surface. It is balanced with a sharp fluke on the opposite side of the hammer surface."
    ]),
    "Cubic Spiked Hammer": ([
        "class": "hammer head",
        "value": 75,
        "description": "a large, square metal head with a broad, flat surface. It is balanced with a sharp fluke on the opposite side of the hammer surface. The top of the hammer is crafted with a squat, dagger-like spike perpendicular to the head."
    ]),
    "Pronged Hammer": ([
        "class": "hammer head",
        "value": 100,
        "description": "a large, square metal head with four prongs jutting from its striking surface. It is balanced with a sharp fluke on the opposite side of the hammer surface. The top of the hammer is crafted with a squat, dagger-like spike perpendicular to the head."
    ]),
    "Cross Hammer": ([
        "class": "hammer head",
        "value": 110,
        "description": "a large, cross-shaped metal head with four prongs jutting from its striking surface. It is balanced with a long, sharp fluke on the opposite side of the hammer surface. The top of the hammer is crafted with a squat, dagger-like spike perpendicular to the head."
    ]),
    "Bladed Hammer": ([
        "class": "hammer head",
        "value": 80,
        "description": "a large, cross-shaped metal head with four prongs jutting from its striking surface. It is balanced with a long, dagger-like blade on the opposite side of the hammer surface."
    ]),
    "Wedge Hammer": ([
        "class": "hammer head",
        "value": 100,
        "description": "a narrow metal head ending in a sharp wedge. It is balanced on the other side by an equal, symmetric wedge."
    ]),
    "Offset Wedge Hammer": ([
        "class": "hammer head",
        "value": 100,
        "description": "a narrow metal head ending in a sharp wedge. It is balanced on the other side by an equal adze-style wedge."
    ]),
    "Pronged-Ball Hammer": ([
        "class": "hammer head",
        "value": 120,
        "description": "a large, square metal head with four prongs jutting from its striking surface. It is balanced with a ball-shaped head on the opposite side."
    ]),
    "Crescent Bardiche": ([
        "class": "bardiche head",
        "value": 75,
        "description": "a head of metal with a massive crescent cutting edge. The edge is connected to the shaft at the bottom of the edge with a sturdy ring and at the head's center at the top of the shaft with a large metal cap."
    ]),
    "Offset Bardiche": ([
        "class": "bardiche head",
        "value": 70,
        "description": "a head of metal with a massive crescent cutting edge. The bottom of the edge is blunted and the top is somewhat elongated. It is connected to the shaft at the top of the shaft with a large metal cap."
    ]),
    "Rhomboidal Bardiche": ([
        "class": "bardiche head",
        "value": 80,
        "description": "a head of metal with a massive rhombus-shaped cutting edge. The edge is connected to the shaft at the bottom of the edge with a sturdy ring and at the head's center at the top of the shaft with a large metal cap."
    ]),
    "Fluked Bardiche": ([
        "class": "bardiche head",
        "value": 100,
        "description": "a head of metal with a massive crescent cutting edge. The upper reverse edge is also sharpened with a broad fluke several inches from the top point. The edge is connected to the shaft at the bottom of the edge with a sturdy ring and at the head's center at the top of the shaft with a large metal cap."
    ]),
    "Spiked Bardiche": ([
        "class": "bardiche head",
        "value": 100,
        "description": "a head of metal with a massive crescent cutting edge. The reverse is counter-weighted by a large fluked spike. The edge is connected to the shaft at the bottom of the edge with a sturdy ring and at the head's center at the top of the shaft with a large metal cap."
    ]),
    "Bill Head": ([
        "class": "bill head",
        "value": 25,
        "description": "a head of metal with a broad, sharpened blade that ends in a pronounced curved hook."
    ]),
    "Spiked Bill Head": ([
        "class": "bill head",
        "value": 50,
        "description": "a head of metal with a broad, sharpened blade that ends in a pronounced curved hook. The reverse side counter-balances with a sharpened spike."
    ]),
    "Spear Bill Head": ([
        "class": "bill head",
        "value": 55,
        "description": "a head of metal with a broad, sharpened blade that ends in an acute thrusting point with a pronounced curved hook veering outward at the base of the thrusting point. The reverse side counter-balances with a sharpened spike."
    ]),
    "Guisarme Head": ([
        "class": "guisarme head",
        "value": 55,
        "description": "a head of metal with a broad, sharpened blade with a pronounced, flattened edge that ends in an acute thrusting point with a pronounced curved hook veering outward at the base of the thrusting point. The reverse side counter-balances with a sharpened spike."
    ]),
    "Splayed Head": ([
        "class": "guisarme head",
        "value": 50,
        "description": "a head of metal with a broad, sharpened blade with a pronounced, flattened edge that splits into a broad thrusting point and a pronounced curved hook veering outward. The reverse side counter-balances with a sharpened spike."
    ]),
    "Single Spike Brandistock": ([
        "class": "brandistock head",
        "value": 15,
        "description": "a head of metal with a long, narrow spike that ends in an acute, sharpened tip. At the base of the primary spike are two perpendicular spikes of about four inches in length, each about 45 degrees offset from the primary spike."
    ]),
    "Double Spike Brandistock": ([
        "class": "brandistock head",
        "value": 30,
        "description": "a head of metal with a long, fork of two spikes that end in acute, sharpened tips. At the base of the primary spikes are two perpendicular spikes of about four inches in length, each about 45 degrees offset from the primary spike."
    ]),
    "Flattened Earspoon": ([
        "class": "earspoon head",
        "value": 15,
        "description": "a head of metal with a long, flattened blade. The broad blade ends in an acute point. At the base of the blade are two counter-balanced flukes jutting out perpendicular to the primary cutting edge."
    ]),
    "Cross-Blade Earspoon": ([
        "class": "earspoon head",
        "value": 35,
        "description": "a head of metal with a long, sharp blade with four cutting edges, each offset by 90 degrees. At the base of the blade are two counter-balanced flukes jutting out perpendicular to the primary cutting edge."
    ]),
    "Double Spike Fork": ([
        "class": "pitchfork head",
        "value": 10,
        "description": "a head of metal with a long, fork of two spikes that end in acute, sharpened tips."
    ]),
    "Triple Spike Fork": ([
        "class": "pitchfork head",
        "value": 20,
        "description": "a head of metal with a long, fork of three spikes that end in acute, sharpened tips."
    ]),
    "Quadruple Spike Fork": ([
        "class": "pitchfork head",
        "value": 30,
        "description": "a head of metal with a long, fork of four spikes that end in acute, sharpened tips."
    ]),
    "Bladed Double Fork": ([
        "class": "fork head",
        "value": 40,
        "description": "a head of metal with two symmetric curved blades that end in acute, sharpened tips."
    ]),
    "Bladed Triple Fork": ([
        "class": "fork head",
        "value": 50,
        "description": "a head of metal with two symmetric curved blades that end in acute, sharpened tips. In the middle is a long, sharpened spike about six inches longer than the other blades."
    ]),
    "Bladed, Spiked Fork": ([
        "class": "fork head",
        "value": 45,
        "description": "a head of metal with two symmetric curved blades that end in acute, sharpened tips. In the middle is a short, sharpened spike about four inches long."
    ]),
    "Simple Trident": ([
        "class": "trident head",
        "value": 20,
        "description": "a head of metal with a long, fork of three spikes that end in acute, sharpened tips."
    ]),
    "Bladed Trident": ([
        "class": "trident head",
        "value": 40,
        "description": "a head of metal with two symmetric curved blades and a broad, straight center blade that all end in acute, sharpened tips."
    ]),
    "Barbed Trident": ([
        "class": "trident head",
        "value": 50,
        "description": "a head of metal with two symmetric convex blades and a broad, straight center blade that all end in tips with pronounced, barbed blades."
    ]),
    "Concave Trident": ([
        "class": "trident head",
        "value": 55,
        "description": "a head of metal with two symmetric concave blades and a broad, straight center blade that all end in tips with pronounced, pronged blades."
    ]),
    "Fluked Partisan": ([
        "class": "partisan head",
        "value": 15,
        "description": "a head of metal with a long, broad blade that ends in an acute, sharpened tip. At the base of the primary blade are two counter-balanced flukes of about four inches in length that are perpendicular to the blade."
    ]),
    "Fanned Partisan": ([
        "class": "partisan head",
        "value": 25,
        "description": "a head of metal with a long, broad blade that ends in an acute, sharpened tip. The base of the blade fans out significantly into two counterbalanced edges, as though they were the base of a triangle."
    ]),
    "Arc Partisan": ([
        "class": "partisan head",
        "value": 35,
        "description": "a head of metal with a long, broad blade that ends in an acute, sharpened tip. The base of the blade fans out significantly into two counterbalanced edges that gracefully arc up into inverted flukes."
    ]),
    "Leaf Partisan": ([
        "class": "partisan head",
        "value": 40,
        "description": "a head of metal with a long, bowed, almost leaf-shaped blade that ends in an acute, sharpened tip. The base of the blade fans out significantly into two counterbalanced edges that gracefully arc up into inverted flukes."
    ]),
    "Crescent Halberd": ([
        "class": "halberd head",
        "value": 75,
        "description": "a head of metal with an extremely broad crescent cutting edge and a symmetrical concave top and bottom. Opposite the cutting edge is a rather large fluke. At the top of the shaft, there is an elongated broad, sharpened blade that ends in an acute point."
    ]),
    "Offset Halberd": ([
        "class": "halberd head",
        "value": 50,
        "description": "a head of metal with an asymmetric crescent cutting edge. The top of the reverse of the edge is somewhat triangular while the bottom is slightly concave. Opposite the cutting edge is a wide, short fluke. At the top of the shaft, there is a short, sharpened, triangular blade."
    ]),
    "Concave Halberd": ([
        "class": "halberd head",
        "value": 85,
        "description": "a head of metal with an extremely broad concave cutting edge. Opposite the cutting edge is a rather large fluke. At the top of the shaft, there is an elongated broad, sharpened blade that ends in an acute point."
    ]),
    "Straight-Edge Halberd": ([
        "class": "halberd head",
        "value": 65,
        "description": "a head of metal with a broad, straight, but slightly angled cutting edge. Opposite the cutting edge is a rather large fluke. At the top of the shaft, there is an elongated broad, sharpened blade that ends in an acute point."
    ]),
    "Bladed Halberd": ([
        "class": "halberd head",
        "value": 95,
        "description": "a head of metal with an extremely broad crescent cutting edge and a symmetrical concave top and bottom. Opposite the cutting edge is another blade - this one with an angled straight blade about one third the size of the primary edge. At the top of the shaft, there is an elongated broad, sharpened blade that ends in an acute point."
    ]),
    "S-Curved Halberd": ([
        "class": "halberd head",
        "value": 80,
        "description": "a head of metal with an extremely broad S-curve shaped cutting edge and a symmetrical concave top and bottom. Opposite the cutting edge is a rather large fluke. At the top of the shaft, there is an elongated broad, sharpened blade that ends in an acute point."
    ]),
    "Double Concave Halberd": ([
        "class": "halberd head",
        "value": 110,
        "description": "a head of metal with an extremely broad concave cutting edge. Opposite the cutting edge is an identical concave cutting surface. At the top of the shaft, there is an elongated broad, sharpened blade that ends in an acute point."
    ]),
    "Fanned Sovnya": ([
        "class": "sovnya head",
        "value": 25,
        "description": "a head of metal with a long, broad blade that fans out into a broad cutting surface."
    ]),
    "Curved Sovnya": ([
        "class": "sovnya head",
        "value": 35,
        "description": "a head of metal with a long, gracefully curving blade that ends in an acute, sharpened tip."
    ]),
    "Leaf Sovnya": ([
        "class": "sovnya head",
        "value": 40,
        "description": "a head of metal with a long, bowed, almost leaf-shaped blade that ends in an acute, sharpened tip."
    ]),
    "Double Fanned Sovnya": ([
        "class": "double sovnya head",
        "value": 25,
        "description": "a head of metal with a long, broad blade that fans out into a broad cutting surface is placed at each end of the shaft."
    ]),
    "Double Curved Sovnya": ([
        "class": "double sovnya head",
        "value": 35,
        "description": "a head of metal with a long, gracefully curving blade that ends in an acute, sharpened tip is placed at each end of the shaft."
    ]),
    "Double Leaf Sovnya": ([
        "class": "double sovnya head",
        "value": 40,
        "description": "a head of metal with a long, bowed, almost leaf-shaped blade that ends in an acute, sharpened tip is placed at each end of the shaft."
    ]),
    "Fanned Spetum": ([
        "class": "spetum head",
        "value": 25,
        "description": "a head of metal with a long, broad blade that ends in an acute, sharpened tip. The base of the blade fans out significantly into two counterbalanced spikes jutting out from the blade at about a forty-five degree angle."
    ]),
    "Arc Spetum": ([
        "class": "spetum head",
        "value": 35,
        "description": "a head of metal with a long, broad blade that ends in an acute, sharpened tip. The base of the blade fans out significantly into two counterbalanced edges that gracefully arc up into inverted flukes."
    ]),
    "Leaf Spetum": ([
        "class": "spetum head",
        "value": 40,
        "description": "a head of metal with a long, bowed, almost leaf-shaped blade that ends in an acute, sharpened tip. The base of the blade fans out significantly into two counterbalanced spikes jutting out from the blade at about a forty-five degree angle."
    ]),
    "Rotated Scythe": ([
        "class": "scythe head",
        "value": 15,
        "description": "a head of metal with a long, gracefully curving blade that ends in an acute, sharpened tip."
    ]),
    "Crescent Scythe": ([
        "class": "scythe head",
        "value": 20,
        "description": "a head of metal with a long, bowed, almost crescent moon shaped blade that ends in an acute, sharpened tip."
    ]),
    "Spiked Scythe": ([
        "class": "scythe head",
        "value": 10,
        "description": "a head of metal with a short triangular blade with the sharp, pointed tip of the cutting blade rotated perpendicular to the shaft."
    ]),
    "Curved Scythe": ([
        "class": "scythe head",
        "value": 10,
        "description": "a head of metal with a long, gracefully curving blade with the sharp, pointed tip of the cutting blade rotated perpendicular to the shaft."
    ]),
    "Beaked Scythe": ([
        "class": "scythe head",
        "value": 10,
        "description": "a head of metal with a long, graceful blade that looks much like the beak of a hawk. The sharp, pointed tip of the cutting blade is rotated perpendicular to the shaft."
    ]),
    "Fauchard Head": ([
        "class": "fauchard head",
        "value": 10,
        "description": "a head of metal with a broad, sharpened blade with a pronounced, flattened edge that ends in an acute thrusting point with a pronounced crescent blade veering outward at the base of the thrusting point."
    ]),
    "Splayed Fauchard": ([
        "class": "fauchard head",
        "value": 20,
        "description": "a head of metal with a broad, sharpened blade with a pronounced, flattened edge that splits into a broad thrusting point and a pronounced curved hook veering outward."
    ]),
    "Crescent Fauchard": ([
        "class": "fauchard head",
        "value": 25,
        "description": "a head of metal with a broad, sharpened blade with a pronounced, flattened edge that splits into a broad crescent blade and a pronounced curved hook veering outward."
    ]),
    "Simple Ahlspiess": ([
        "class": "ahlspiess head",
        "value": 20,
        "description": "a head of metal with a long spike that ends in acute, sharpened tip. At the base of the spike is a perpendicular rondel guard."
    ]),
    "Bladed Ahlspiess": ([
        "class": "ahlspiess head",
        "value": 40,
        "description": "a head of metal with a broad, straight blade that ends in an acute, sharpened tip. At the base of the spike is a perpendicular rondel guard."
    ]),
    "Simple Lance": ([
        "class": "lance head",
        "value": 5,
        "description": "a head of metal with a long spike that ends in acute, sharpened tip."
    ]),
    "Bladed Lance": ([
        "class": "lance head",
        "value": 15,
        "description": "a head of metal with a long, blade that ends in acute, sharpened tip."
    ]),
    "Leaf Lance": ([
        "class": "lance head",
        "value": 25,
        "description": "a head of metal with a short, leaf-shaped blade that ends in acute, sharpened tip."
    ]),
    "Crescent Voulge": ([
        "class": "voulge head",
        "value": 15,
        "description": "a head of metal with a massive crescent cutting edge. The upper reverse edge is also sharpened with a broad fluke at the midpoint of the blade."
    ]),
    "Parallelogram Voulge": ([
        "class": "voulge head",
        "value": 10,
        "description": "a head of metal with a massive parallelogram-shaped cutting edge. The upper reverse edge is also sharpened with a broad fluke at the midpoint of the blade."
    ]),
    "S-Shaped Voulge": ([
        "class": "voulge head",
        "value": 15,
        "description": "a head of metal with a massive S-shaped cutting edge. The upper reverse edge is also sharpened with a broad fluke at the midpoint of the blade."
    ]),
    "Glaive Head": ([
        "class": "glaive head",
        "value": 10,
        "description": "a head of metal with a broad, sharpened blade with a pronounced, flattened edge that ends in an acute thrusting point. The reverse side counter-balances with a sharpened fluke."
    ]),
    "Crescent Glaive": ([
        "class": "glaive head",
        "value": 20,
        "description": "a head of metal with a broad, sharpened blade with a pronounced, crescent edge that ends in an acute thrusting point. The reverse side counter-balances with a sharpened fluke."
    ]),
    "S-Shaped Glaive": ([
        "class": "glaive head",
        "value": 25,
        "description": "a head of metal with a broad, sharpened blade with a pronounced, S-shaped edge that ends in an acute thrusting point. The reverse side counter-balances with a sharpened fluke."
    ]),
    "Curved Glaive": ([
        "class": "glaive head",
        "value": 15,
        "description": "a head of metal with a broad, sharpened blade with a pronounced, curved edge that ends in an acute thrusting point. The reverse side counter-balances with a sharpened spike rotated about forty-five degrees."
    ]),
    "Bladed Spear": ([
        "class": "spear head",
        "value": 10,
        "description": "a head of metal with a broad, straight blade that ends in an acute, sharpened tip."
    ]),
    "Leaf Spear": ([
        "class": "spear head",
        "value": 15,
        "description": "a head of metal with a broad, leaf-shaped blade that ends in an acute, sharpened tip."
    ]),
    "Pronged Spear": ([
        "class": "spear head",
        "value": 25,
        "description": "a head of metal with a broad, leaf-shaped blade that ends in an acute, sharpened tip. At the base are two prongs that are perpendicular to the primary cutting edge."
    ]),
    "Rhomboidal Spear": ([
        "class": "spear head",
        "value": 15,
        "description": "a head of metal with a broad, rhomboidal blade that ends in an acute, sharpened tip."
    ]),
]);
