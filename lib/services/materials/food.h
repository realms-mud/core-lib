//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef food_h
#define food_h

protected mapping food =
([
    "tomato": ([
        "type": "vegetable",
        "subtype": "tomato",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "tomato seed": 1
        ]),
        "default description": "A plump, vibrant red fruit with a subtle balance of sweetness and "
            "acidity. Its sun-ripened skin glows with an almost magical luster "
            "that speaks of fertile soils and careful tending.",
        "base experience": 1,
    ]),
    "cherry tomato": ([
        "type": "vegetable",
        "subtype": "tomato",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "cherry tomato seed": 1
        ]),
        "default description": "Small, jewel-like orbs that burst with intensely sweet flavor. "
            "These tiny red treasures grow in cheerful clusters, their skins "
            "stretched taut over their juicy interiors.",
        "base experience": 1,
    ]),
    "grape tomato": ([
        "type": "vegetable",
        "subtype": "tomato",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "grape tomato seed": 1
        ]),
        "default description": "Oblong miniature tomatoes with a firm texture and concentrated "
            "flavor. Their elongated shape and rich red color make them appear "
            "like rubies plucked from a master gardener's paradise.",
        "base experience": 1,
    ]),
    "yellow tomato": ([
        "type": "vegetable",
        "subtype": "tomato",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "yellow tomato seed": 1
        ]),
        "default description": "Golden-hued tomatoes with a milder, less acidic flavor than their "
            "red cousins. They seem to capture sunlight within their flesh, "
            "glowing with a gentle warmth when sliced open.",
        "base experience": 1,
    ]),
    "roma tomato": ([
        "type": "vegetable",
        "subtype": "tomato",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "roma tomato seed": 1
        ]),
        "default description": "Egg-shaped tomatoes with thick walls and few seeds. Their dense, "
            "meaty flesh holds concentrated flavor that intensifies wonderfully "
            "when cooked, releasing aromatic essences.",
        "base experience": 1,
    ]),
    "purple tomato": ([
        "type": "vegetable",
        "subtype": "tomato",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "purple tomato seed": 1
        ]),
        "default description": "Deep amethyst-colored tomatoes with a smoky sweetness. Their unusual "
            "hue suggests mystical properties, and some claim they bring vivid "
            "dreams to those who eat them before sleeping.",
        "base experience": 1,
    ]),
    "green tomato": ([
        "type": "vegetable",
        "subtype": "tomato",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "green tomato seed": 1
        ]),
        "default description": "Firm, unripened tomatoes with a tangy, almost citrus-like flavor. "
            "Their crisp texture and bright acidity make them perfect for those "
            "who enjoy sharper tastes.",
        "base experience": 1,
    ]),
    "striped tomato": ([
        "type": "vegetable",
        "subtype": "tomato",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "striped tomato seed": 1
        ]),
        "default description": "Remarkable tomatoes with alternating bands of red and yellow that "
            "seem too perfect to be natural. Their sweet flesh carries subtle "
            "hints of tropical fruit rarely found in common varieties.",
        "base experience": 1,
    ]),
    "potato": ([
        "type": "vegetable",
        "subtype": "tuber",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "potato eye": 1
        ]),
        "default description": "A humble earth-treasure with brown skin hiding versatile, starchy "
            "flesh. These reliable tubers have sustained countless generations "
            "through harsh winters and lean times.",
        "base experience": 1,
    ]),
     "russet potato": ([
        "type": "vegetable",
        "subtype": "tuber",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "russet potato eye": 1
        ]),
        "default description": "Large, oblong tubers with rough brown skin and fluffy white flesh. "
            "When baked, they develop a delightfully crisp exterior that gives way "
            "to a cloud-like interior.",
        "base experience": 1,
    ]),
    "red potato": ([
        "type": "vegetable",
        "subtype": "tuber",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "red potato eye": 1
        ]),
        "default description": "Round tubers with thin, vibrant red skin and waxy, creamy flesh "
            "that holds its shape when cooked. Some believe their rosy hue brings "
            "good fortune to households that store them.",
        "base experience": 1,
    ]),
    "white potato": ([
        "type": "vegetable",
        "subtype": "tuber",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "white potato eye": 1
        ]),
        "default description": "Smooth-skinned, pale tubers with a delicate flavor and medium "
            "starch content. Their versatile nature makes them beloved by cooks "
            "from humble cottages to royal kitchens.",
        "base experience": 1,
    ]),
    "yellow potato": ([
        "type": "vegetable",
        "subtype": "tuber",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "yellow potato eye": 1
        ]),
        "default description": "Golden-fleshed tubers with a naturally buttery flavor and creamy "
            "texture. Their sunny interior seems to capture the essence of summer, "
            "even when stored through winter months.",
        "base experience": 1,
    ]),
    "purple potato": ([
        "type": "vegetable",
        "subtype": "tuber",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "purple potato eye": 1
        ]),
        "default description": "Striking tubers with deep violet flesh that maintains its color when "
            "cooked. Their slightly nutty flavor and unusual appearance have made "
            "them favorites in ceremonial feasts.",
        "base experience": 1,
    ]),
    "fingerling potato": ([
        "type": "vegetable",
        "subtype": "tuber",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "fingerling potato eye": 1
        ]),
        "default description": "Small, elongated tubers with thin skin and a delightful, waxy "
            "texture. Their distinctive shape inspired folklore about earth "
            "spirits leaving their fingerprints on growing potatoes.",
        "base experience": 1,
    ]),
    "petite potato": ([
        "type": "vegetable",
        "subtype": "tuber",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "petite potato eye": 1
        ]),
        "default description": "Tiny, bite-sized tubers that cook quickly and absorb flavors "
            "readily. Their diminutive size belies their rich flavor, making them "
            "prized additions to travelers' stews.",
        "base experience": 1,
    ]),
    "carrot": ([
        "type": "vegetable",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "carrot seed": 1
        ]),
        "default description": "Vibrant orange roots that grow straight and true in well-tended "
            "soil. Their sweet, earthy flavor carries whispers of sunshine, and "
            "some claim they improve night vision.",
        "base experience": 1,
    ]),
    "turnip": ([
        "type": "vegetable",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "turnip seed": 1
        ]),
        "default description": "Round, white-fleshed roots with purple shoulders where they emerged "
            "from soil. Their peppery bite mellows into sweetness when cooked, "
            "offering comfort in cold seasons.",
        "base experience": 1,
    ]),
    "parsnip": ([
        "type": "vegetable",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "parsnip seed": 1
        ]),
        "default description": "Cream-colored roots resembling pale carrots with a distinctively "
            "sweet, nutty flavor that intensifies after the first frost. Winter's "
            "touch transforms them into natural candy.",
        "base experience": 1,
    ]),
    "onion": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "onion seed": 1
        ]),
        "default description": "Layered bulbs with papery skin and pungent flesh that brings tears "
            "to the eyes. Their transformative power in cooking has earned them "
            "reverence in culinary traditions across the realms.",
        "base experience": 1,
    ]),
    "yellow onion": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "yellow onion seed": 1
        ]),
        "default description": "Golden-skinned bulbs with a perfect balance of sweetness and "
            "pungency. When properly caramelized, they transform into a treasure "
            "more valuable to cooks than gold itself.",
        "base experience": 1,
    ]),
    "red onion": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "red onion seed": 1
        ]),
        "default description": "Purple-red bulbs with crisp, colorful layers that add beauty and "
            "sharp flavor to meals. Their vibrant hue suggests magical properties, "
            "though most value them simply for their taste.",
        "base experience": 1,
    ]),
    "white onion": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "white onion seed": 1
        ]),
        "default description": "Clean, ivory-skinned bulbs with a sharper, more assertive flavor "
            "than their yellow cousins. Their crisp texture maintains integrity "
            "even when cooked in fierce flames.",
        "base experience": 1,
    ]),
    "sweet onion": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "sweet onion seed": 1
        ]),
        "default description": "Pale, mild bulbs that can be eaten raw without the usual onion bite. "
            "Their gentle nature makes them beloved by those who normally avoid "
            "their more aggressive relatives.",
        "base experience": 1,
    ]),
     "scallion": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "scallion seed": 1
        ]),
        "default description": "Slender green stalks with tiny white bulbs that offer a gentle "
            "onion flavor. Their quick growth has made them symbols of resilience "
            "and swift recovery in some rural traditions.",
        "base experience": 1,
    ]),
    "hardneck garlic": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "hardneck garlic seed": 1
        ]),
        "default description": "Robust garlic variety with a woody central stem and large, easy-to-"
            "peel cloves. Its powerful flavor carries protective properties "
            "against both mundane and mystical threats.",
        "base experience": 1,
    ]),
    "silverskin garlic": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "silverskin garlic seed": 1
        ]),
        "default description": "Brilliant white garlic with multiple layers of small cloves and "
            "exceptional storage life. The metallic sheen of its skin is said to "
            "reflect harmful energies away from households.",
        "base experience": 1,
    ]),
    "garlic": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "garlic seed": 1
        ]),
        "default description": "Pungent bulbs composed of paper-wrapped cloves with intense aroma "
            "and flavor. Legends claim it wards off vampires, but cooks know its "
            "true magic lies in transforming meals.",
        "base experience": 1,
    ]),
    "burgundy garlic": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "burgondy garlic seed": 1
        ]),
        "default description": "Striking garlic with purple-red outer layers concealing ivory "
            "cloves within. Its rich flavor carries earthy undertones rare in "
            "other varieties, suggesting ancient lineage.",
        "base experience": 1,
    ]),
    "red garlic": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "red garlic seed": 1
        ]),
        "default description": "Vibrant garlic with rosy skin and pink-tinged cloves offering a "
            "robust, spicy flavor. Some claim its color indicates superior "
            "protective properties against malevolent forces.",
        "base experience": 1,
    ]),
    "black garlic": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "black garlic seed": 1
        ]),
        "default description": "Fermented garlic with jet-black cloves and a molasses-like "
            "sweetness without garlic's typical bite. This alchemical "
            "transformation creates mysterious new properties and flavors.",
        "base experience": 1,
    ]),
    "scape": ([
        "type": "vegetable",
        "subtype": "green",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "hardneck garlic seed": 1
        ]),
        "default description": "Curling green shoots that emerge from hardneck garlic with a mild, "
            "grassy flavor. Their spiral form inspired tales of garlic trying to "
            "write messages from the earth spirits.",
        "base experience": 1,
    ]),
    "ramp": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "ramp seed": 1
        ]),
        "default description": "Wild forest alliums with broad green leaves and white bulbs that "
            "combine garlic and onion flavors. Forest dwellers celebrate their "
            "spring emergence with feasts and festivals.",
        "base experience": 1,
    ]),
    "wild garlic": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "wild garlic seed": 1
        ]),
        "default description": "Untamed garlic relative with delicate white flowers and slender "
            "bulbs. Its appearance in woodlands signals places where magic runs "
            "close to the surface of the world.",
        "base experience": 1,
    ]),
    "elephant garlic": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "elephant garlic seed": 1
        ]),
        "default description": "Massive garlic relative with bulbs the size of a fist and a milder "
            "flavor than true garlic. Their impressive size suggests supernatural "
            "intervention in their growth.",
        "base experience": 1,
    ]),
    "daylily": ([
        "type": "vegetable",
        "subtype": "tuber",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "daylily seed": 1
        ]),
        "default description": "Edible tubers from flowering plants whose blossoms last but a "
            "single day. Though humble in appearance, their natural sweetness "
            "carries whispers of summer sunshine.",
        "base experience": 1,
    ]),
    "radish": ([
        "type": "vegetable",
        "subtype": "stem",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "radish seed": 1
        ]),
        "default description": "Crisp, peppery roots that grow quickly and announce their presence "
            "with bright colors and sharp flavors. Their fiery personality makes "
            "them favorites in tales of troublemakers.",
        "base experience": 1,
    ]),
    "horseradish": ([
        "type": "vegetable",
        "subtype": "root",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "horseradish seed": 1
        ]),
        "default description": "Unassuming white roots that conceal a fiery nature, releasing "
            "volatile oils when cut that can bring tears and clear sinuses. Some "
            "claim they can temporarily grant clear sight.",
        "base experience": 1,
    ]),
    "shalot": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "shalot seed": 1
        ]),
        "default description": "Copper-skinned clustered bulbs with mild, sophisticated flavor. "
            "Their elegant complexity has made them staples in the kitchens of "
            "nobility and renowned taverns alike.",
        "base experience": 1,
    ]),
    "kohlrabi": ([
        "type": "vegetable",
        "subtype": "stem",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "kohlrabi seed": 1
        ]),
        "default description": "Alien-looking vegetables with swollen, bulbous stems and leaf "
            "stalks radiating outward like green rays. Their crisp, sweet flesh "
            "belies their otherworldly appearance.",
        "base experience": 1,
    ]),
    "beet": ([
        "type": "vegetable",
        "subtype": "root",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "beet seed": 1
        ]),
        "default description": "Ruby-fleshed roots that bleed crimson when cut, revealing their "
            "sweet, earthy nature. Their vivid color has made them symbols of life "
            "force and vitality in many cultures.",
        "base experience": 1,
    ]),
    "sweet potato": ([
        "type": "vegetable",
        "subtype": "tuber",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "sweet potato seed": 1
        ]),
        "default description": "Orange-fleshed tubers with copper skin and natural sweetness that "
            "intensifies when cooked. They symbolize abundance and prosperity in "
            "harvest celebrations across the realms.",
        "base experience": 1,
    ]),
    "rutabaga": ([
        "type": "vegetable",
        "subtype": "root",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "rutabaga seed": 1
        ]),
        "default description": "Large, yellow-fleshed roots with purple-tinged skin and a complex "
            "sweet-bitter flavor. Their hardiness against frost makes them valued "
            "staples in northern provinces.",
        "base experience": 1,
    ]),
    "ginger": ([
        "type": "vegetable",
        "subtype": "root",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "ginger seed": 1
        ]),
        "default description": "Knotted, fibrous rhizomes with golden flesh and fiery flavor that "
            "warms from within. Their heat is said to kindle inner fire against "
            "winter chills and malevolent spirits alike.",
        "base experience": 1,
    ]),
    "yam": ([
        "type": "vegetable",
        "subtype": "tuber",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "yam seed": 1
        ]),
        "default description": "Massive tubers with rough, bark-like skin and starchy white flesh. "
            "Their impressive size and stored energy have made them symbols of "
            "endurance and sustaining power.",
        "base experience": 1,
    ]),
    "chive": ([
        "type": "vegetable",
        "subtype": "green",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "chive seed": 1
        ]),
        "default description": "Slender green allium shoots with hollow centers and delicate onion "
            "flavor. Their resilience after cutting has made them symbols of "
            "rebirth in spring planting rituals.",
        "base experience": 1,
    ]),
    "celery": ([
        "type": "vegetable",
        "subtype": "stem",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "celery seed": 1
        ]),
        "default description": "Crisp, watery stalks with pronounced channels and distinctive "
            "aromatic flavor. Old tales claim eating them burns more energy than "
            "they provide, making them favorites of fasting mystics.",
        "base experience": 1,
    ]),
    "asparagus": ([
        "type": "vegetable",
        "subtype": "stem",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "asparagus seed": 1
        ]),
        "default description": "Tender green spears that emerge like soldiers from the earth in "
            "springtime. Their distinctive aroma marks those who consume them, "
            "leading to much folklore about their mystical properties.",
        "base experience": 1,
    ]),
    "rhubarb": ([
        "type": "vegetable",
        "subtype": "stem",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "rhubarb seed": 1
        ]),
        "default description": "Ruby-red stalks with a mouth-puckering sourness that transforms "
            "magically when sweetened. Their poisonous leaves remind gardeners "
            "that beauty and danger often grow from the same root.",
        "base experience": 1,
    ]),
    "leek": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "leek seed": 1
        ]),
        "default description": "Tall alliums with white bases that gradually transform into "
            "blue-green leaves. Their mild flavor and proud stance have made them "
            "emblems of national pride in several mountain kingdoms.",
        "base experience": 1,
    ]),
    "fennel": ([
        "type": "vegetable",
        "subtype": "bulb",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "fennel seed": 1
        ]),
        "default description": "Anise-scented bulbs with feathery fronds that resemble dill. Their "
            "licorice notes are said to please woodland spirits, making them "
            "popular offerings at forest shrines.",
        "base experience": 1,
    ]),
    "snow pea": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "snow pea": 1
        ]),
        "default description": "Flat, translucent pods with tiny peas visible within like jewels "
            "under ice. They bring the freshness of early spring to any meal, "
            "even in the depths of winter.",
        "base experience": 1,
    ]),
    "green bean": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "green bean": 1
        ]),
        "default description": "Slender, crisp pods that snap cleanly when fresh. Their verdant "
            "color and abundant growth have made them symbols of plentiful "
            "harvests and generous nature.",
        "base experience": 1,
    ]),
    "wax bean": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "wax bean": 1
        ]),
        "default description": "Pale yellow beans with a buttery appearance and tender texture. "
            "Their waxy sheen inspired tales of beans grown from candlemakers' "
            "discarded scraps touched by moonlight.",
        "base experience": 1,
    ]),
    "lima bean": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "lima bean": 1
        ]),
        "default description": "Broad, flattened beans with a starchy texture and subtle "
            "creaminess. Their pale green hue and buttery flavor make them "
            "favorites in country kitchens throughout the southern realms.",
        "base experience": 1,
    ]),
    "chickpea": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "chickpea": 1
        ]),
        "default description": "Round, knobby legumes with a nutty flavor and versatile nature. "
            "Their ability to be ground into flour or kept whole makes them "
            "treasured provisions for desert caravans and nomad tribes.",
        "base experience": 1,
    ]),
    "navy bean": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "navy bean": 1
        ]),
        "default description": "Small white beans with remarkable ability to absorb flavors while "
            "maintaining their shape. Their high protein content makes them "
            "staples aboard ships for long voyages across stormy seas.",
        "base experience": 1,
    ]),
    "fava bean": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "fava bean": 1
        ]),
        "default description": "Large, flat beans enclosed in thick pods and secondary skins. "
            "Ancient folklore associates them with communication with ancestral "
            "spirits, making them feature in many traditional rituals.",
        "base experience": 1,
    ]),
    "lupin bean": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "lupin bean": 1
        ]),
        "default description": "White beans that must be soaked repeatedly to remove bitterness "
            "before eating. Their association with the wolf flower gives them a "
            "reputation for imbuing cunning and keen senses.",
        "base experience": 1,
    ]),
    "mung bean": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "mung bean": 1
        ]),
        "default description": "Small, olive-green beans that sprout easily into nutritious "
            "shoots. Their ability to transform from seed to vibrant growth even "
            "in darkness symbolizes hope in many eastern traditions.",
        "base experience": 1,
    ]),
    "runner bean": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "runner bean": 1
        ]),
        "default description": "Vigorous climbing beans with striking scarlet flowers followed by "
            "long pods. Their enthusiasm for vertical growth has made them "
            "metaphors for ambition and reaching for impossible heights.",
        "base experience": 1,
    ]),
    "pigeon pea": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "pigeon pea": 1
        ]),
        "default description": "Small, resilient legumes that thrive in poor soil and drought "
            "conditions. Their hardiness has made them symbols of perseverance "
            "in folk tales throughout tropical regions.",
        "base experience": 1,
    ]),
    "pinto bean": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "pinto bean": 1
        ]),
        "default description": "Speckled beans that turn uniform pink-brown when cooked, seeming "
            "to undergo a magical transformation. Their name means 'painted,' "
            "referring to their artistic mottled appearance when raw.",
        "base experience": 1,
    ]),
    "black turtle bean": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "black turtle bean": 1
        ]),
        "default description": "Shiny, jet-black beans that release a purple-black broth when "
            "cooked. Their dark color led to associations with underworld deities "
            "and protective magic in ancient traditions.",
        "base experience": 1,
    ]),
    "soybean": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "soybean": 1
        ]),
        "default description": "Versatile yellow-beige beans with remarkable transformative "
            "potential. Alchemists value their ability to become milk, curd, "
            "sauce, or flour through various magical processes.",
        "base experience": 1,
    ]),
    "black-eyed pea": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "black-eyed pea": 1
        ]),
        "default description": "Cream-colored legumes with distinctive black spots resembling "
            "watchful eyes. Tradition holds that eating them at year's beginning "
            "ensures the spirits of prosperity watch over you.",
        "base experience": 1,
    ]),
    "cannellini bean": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "cannellini bean": 1
        ]),
        "default description": "Elegant white kidney-shaped beans with tender texture and mild "
            "flavor. Their refined nature makes them favorites in the sophisticated "
            "cuisines of sun-drenched coastal regions.",
        "base experience": 1,
    ]),
    "great northern bean": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "great northern bean": 1
        ]),
        "default description": "Large white beans with firm texture that hold their shape well when "
            "cooked. They're named for the northern lights, as their pale color "
            "recalls the ghostly illumination of winter skies.",
        "base experience": 1,
    ]),
    "kidney bean": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "kidney bean": 1
        ]),
        "default description": "Deep red beans shaped like the organ they're named for, with a "
            "robust flavor and meaty texture. Some healers prescribe them to "
            "strengthen the corresponding body part.",
        "base experience": 1,
    ]),
    "wheat": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "wheat seed": 1
        ]),
        "default description": "Golden grain that forms the foundation of civilization itself. Its "
            "amber waves ripple like a sea of prosperity, promising bread, ale, "
            "and sustenance to those who cultivate it faithfully.",
        "base experience": 1,
    ]),
    "flax": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "flax seed": 1
        ]),
        "default description": "Blue-flowered plants yielding tiny, glossy seeds rich in oil and "
            "fiber. Their dual gifts of linen cloth and nourishing oil make them "
            "uniquely valuable to resourceful communities.",
        "base experience": 1,
    ]),
    "barley": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "barley seed": 1
        ]),
        "default description": "Hardy grain with bristling awns like miniature spears protecting "
            "its bounty. Its ability to thrive in harsh conditions has made it "
            "a stalwart ally of frontier settlements.",
        "base experience": 1,
    ]),
    "wild rice": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "wild rice seed": 1
        ]),
        "default description": "Long, dark aquatic grain that grows in clear northern waters. Its "
            "nutty flavor carries whispers of forest and lake, making it prized by "
            "druids and those who honor water spirits.",
        "base experience": 1,
    ]),
    "rye": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "rye seed": 1
        ]),
        "default description": "Dark, resilient grain that thrives where others fail, yielding "
            "hearty bread with deep flavor. Its hardiness in cold lands makes it "
            "associated with endurance and winter's bite.",
        "base experience": 1,
    ]),
    "amaranth": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "amaranth seed": 1
        ]),
        "default description": "Ancient grain with vivid red-purple flowers and tiny seeds filled "
            "with remarkable nutrition. Its name means 'unfading,' and it's "
            "often associated with immortality in ancient lore.",
        "base experience": 1,
    ]),
    "millet": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "millet seed": 1
        ]),
        "default description": "Tiny, round golden grains that grow quickly even in poor soil and "
            "drought. Birds particularly treasure these seeds, leading to folklore "
            "about millet being blessed by sky spirits.",
        "base experience": 1,
    ]),
    "oat": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "oat seed": 1
        ]),
        "default description": "Nourishing grain that thrives in cool, moist conditions. Its "
            "ability to impart sustained energy and warmth has made it the "
            "breakfast choice of heroes setting out on quests.",
        "base experience": 1,
    ]),
    "quinoa": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "quinoa seed": 1
        ]),
        "default description": "Tiny disk-shaped seeds with remarkable nutritional properties and "
            "spiral-like appearance when cooked. Highland peoples consider it "
            "sacred, calling it the mother of all grains.",
        "base experience": 1,
    ]),
    "rice": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "rice seed": 1
        ]),
        "default description": "Pearly white grains that flourish in standing water, defying normal "
            "plant behavior. Its cultivation transforms landscapes into reflective "
            "pools that mirror the sky above.",
        "base experience": 1,
    ]),
    "basmati rice": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "basmati rice seed": 1
        ]),
        "default description": "Aromatic long-grain rice prized for its fragrance reminiscent of "
            "flowers and nuts. Its name means 'fragrant,' and cooking releases an "
            "enchanting aroma that perfumes entire households.",
        "base experience": 1,
    ]),
    "spelt": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "spelt seed": 1
        ]),
        "default description": "Ancient, primitive wheat with distinctive hull that protects the "
            "grain from pests and weather. This resilient ancestor of wheat "
            "carries whispers of farming's earliest days.",
        "base experience": 1,
    ]),
    "teff": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "teff seed": 1
        ]),
        "default description": "Tiny grain, the world's smallest, yet packed with remarkable "
            "nutrition and subtle, sweet flavor. Its name derives from 'lost' in "
            "an ancient tongue, as each tiny seed easily disappears.",
        "base experience": 1,
    ]),
    "buckwheat": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "buckwheat seed": 1
        ]),
        "default description": "Triangular seeds with earthy flavor that aren't true grain but "
            "function similarly in cooking. Their distinctive shape is said to "
            "represent the three realms: earth, sky, and underworld.",
        "base experience": 1,
    ]),
    "sorghum": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "sorghum seed": 1
        ]),
        "default description": "Round, drought-resistant grain that grows on tall stalks like "
            "miniature corn. Its remarkable ability to withstand brutal heat has "
            "made it a survival staple in sun-scorched lands.",
        "base experience": 1,
    ]),
    "triticale": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "triticale seed": 1
        ]),
        "default description": "Hybrid grain combining wheat and rye's strengths, created through "
            "agricultural alchemy. Its existence demonstrates how human ingenuity "
            "can enhance even nature's most perfect designs.",
        "base experience": 1,
    ]),
    "chia": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "chia seed": 1
        ]),
        "default description": "Tiny seeds that absorb water and create gel-like puddings with "
            "mild, nutty flavor. Messengers and couriers favor them for providing "
            "endurance beyond what their small size suggests possible.",
        "base experience": 1,
    ]),
    "fonio": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "fonio seed": 1
        ]),
        "default description": "Ancient micro-grain that matures with extraordinary speed, ready to "
            "harvest in just six to eight weeks. Desert peoples revere it as a "
            "gift from spirits who abhor hunger.",
        "base experience": 1,
    ]),
    "flour corn": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "flour corn seed": 1
        ]),
        "default description": "Soft-kerneled corn variety that grinds easily into fine powder for "
            "baking. Its starchy nature makes it invaluable for creating breads "
            "that rise without traditional wheat gluten.",
        "base experience": 1,
    ]),
    "popcorn": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "popcorn seed": 1
        ]),
        "default description": "Hard-kerneled corn with moisture trapped inside that explosively "
            "transforms when heated. Children delight in its magical transmutation "
            "from hard seed to cloudlike puff.",
        "base experience": 1,
    ]),
    "dent corn": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "dent corn seed": 1
        ]),
        "default description": "Field corn with distinctive dents in each kernel when dried. Its "
            "high starch content makes it perfect for creating corn meal that "
            "bakes into hearty bread with remarkable sustaining power.",
        "base experience": 1,
    ]),
    "flint corn": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "flint corn seed": 1
        ]),
        "default description": "Hard-kerneled corn in brilliant jewel-like colors of blue, red, "
            "white, and yellow. Ancient peoples believed its multicolored kernels "
            "represented the cardinal directions and elemental forces.",
        "base experience": 1,
    ]),
    "sweet corn": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "sweet corn seed": 1
        ]),
        "default description": "Tender yellow kernels bursting with natural sugar and sunshine. "
            "Summer festivals often feature this beloved crop, with folklore "
            "claiming each kernel holds a day's worth of happiness.",
        "base experience": 1,
    ]),
    "waxy corn": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "waxy corn seed": 1
        ]),
        "default description": "Specialized corn variety with translucent, glossy kernels and unique "
            "starch properties. Alchemists prize it for creating binding agents "
            "that work even in the presence of magical energies.",
        "base experience": 1,
    ]),
    "pod corn": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "pod corn seed": 1
        ]),
        "default description": "Unusual corn where each kernel develops its own leafy husk. "
            "Considered sacred by some cultures who believe it represents corn "
            "in its original wild form, touched by divine hands.",
        "base experience": 1,
    ]),
    "striped maize": ([
        "type": "vegetable",
        "subtype": "grain",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "striped maize seed": 1
        ]),
        "default description": "Decorative corn with striking patterns of color running lengthwise "
            "on each kernel. Garden witches claim its patterns can be read like "
            "runes to predict the coming season's weather.",
        "base experience": 1,
    ]),
    "red lentil": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "red lentil": 1
        ]),
        "default description": "Tiny, salmon-colored discs that cook quickly into a golden puree. "
            "Their sunset hue is said to represent the fire element, making them "
            "favored offerings at summer solstice celebrations.",
        "base experience": 1,
    ]),
    "green lentil": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "green lentil": 1
        ]),
        "default description": "Earthy, peppery lentils that hold their shape when cooked. Their "
            "verdant color associates them with growth and renewal, making them "
            "traditional first meals for spring planting crews.",
        "base experience": 1,
    ]),
    "peanut": ([
        "type": "vegetable",
        "subtype": "legume",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "peanut": 1
        ]),
        "default description": "Peculiar legumes that grow underground in papery shells containing "
            "protein-rich seeds. Their unusual growth habit led to folklore about "
            "earth spirits hiding treasure beneath the soil.",
        "base experience": 1,
    ]),
    "sweet yellow pepper": ([
        "type": "pepper",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "sweet yellow pepper seed": 1
        ]),
        "default description": "Sunny golden peppers with a mild, sugary flavor and crisp texture. "
            "Their cheerful color is said to ward off melancholy, making them "
            "popular ingredients in tonics for lifting spirits.",
        "base experience": 1,
    ]),
    "sweet orange pepper": ([
        "type": "pepper",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "sweet orange pepper seed": 1
        ]),
        "default description": "Vibrant tangerine-hued peppers with juicy walls and fruity flavor. "
            "Their rich color signals abundant vitamins that healers recommend for "
            "strengthening night vision and warding off winter ailments.",
        "base experience": 1,
    ]),
    "sweet red pepper": ([
        "type": "pepper",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "sweet red pepper seed": 1
        ]),
        "default description": "Ruby-red peppers fully ripened to develop rich sweetness and complex "
            "flavor. Their brilliant color symbolizes vitality and passion, making "
            "them traditional gifts between new lovers.",
        "base experience": 1,
    ]),
    "green pepper": ([
        "type": "pepper",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "green pepper seed": 1
        ]),
        "default description": "Unripened peppers with grassy flavor and satisfying crunch. Some "
            "kitchen witches believe their bitter notes can absorb negative "
            "energies when hung above cooking areas.",
        "base experience": 1,
    ]),
    "long pepper": ([
        "type": "fruit",
        "subtype": "pepper",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "crafting materials": ([
            "long pepper seed": 1
        ]),
        "default description": "Catkin-like spikes of tiny fruits with a sharp, complex heat. "
            "Long pepper was prized in kitchens before black pepper became dominant.",
        "base experience": 1,
    ]),
    "cayenne pepper": ([
        "type": "fruit",
        "subtype": "pepper",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "crafting materials": ([
            "cayenne pepper seed": 1
        ]),
        "default description": "Slender, bright red peppers with intense heat and pungency. "
            "Used to add fire to dishes and remedies.",
        "base experience": 1,
    ]),
    "bird's eye chili": ([
        "type": "fruit",
        "subtype": "pepper",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "crafting materials": ([
            "bird's eye chili seed": 1
        ]),
        "default description": "Tiny, potent peppers that pack a fiery punch. Their heat "
            "is legendary among spice lovers.",
        "base experience": 1,
    ]),
    "dragon pepper": ([
        "type": "fruit",
        "subtype": "pepper",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "crafting materials": ([
            "dragon pepper seed": 1
        ]),
        "default description": "A legendary pepper said to be so hot it can "
            "make a grown warrior weep. Its fiery red color warns of its potency.",
        "base experience": 1,
    ]),
    "jalapeno pepper": ([
        "type": "fruit",
        "subtype": "pepper",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "crafting materials": ([
            "jalapeno seed":1
        ]),
        "default description": "Medium-sized peppers with a smoky, spicy flavor. "
            "Their heat level is perfect for adding warmth without overwhelming dishes.",
        "base experience" : 1,
    ]),
    "habanero pepper": ([
        "type": "fruit",
        "subtype": "pepper",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "crafting materials": ([
            "habanero seed":1
        ]),
        "default description": "Small, lantern-shaped peppers with a fiery heat that lingers. "
            "Their origins give them a fruity undertone that enhances "
            "salsas and spicy dishes.",
        "base experience" : 1,
    ]),
    "serrano pepper": ([
        "type": "fruit",
        "subtype": "pepper",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "crafting materials": ([
            "serrano seed": 1
        ]),
        "default description": "Thin-skinned peppers with a bright, crisp flavor and moderate heat. "
        "Their vibrant green color adds freshness to dishes, making them a "
        "favorite in salsas and sauces.",
        "base experience" : 1,
    ]),
    "red chili pepper": ([
        "type": "fruit",
        "subtype": "pepper",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "crafting materials": ([
            "red chili seed":1
        ]),
        "default description": "Dried red peppers with a smoky, spicy flavor that adds depth to "
            "soups and stews. Their intense heat is balanced by a subtle sweetness.",
            "base experience" : 1,
    ]),
    "green chili pepper": ([
        "type": "fruit",
        "subtype": "pepper",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "crafting materials": ([
            "green chili seed":1
        ]),
        "default description": "Fresh green peppers with a crisp, grassy flavor and moderate heat. "
            "Their vibrant color and bright taste make them perfect for salads and "
            "salsas.",
        "base experience": 1,
    ]),
    "tabasco pepper": ([
        "type": "fruit",
        "subtype": "pepper",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "crafting materials": ([
            "tabasco seed": 1
        ]),
        "default description": "Fiery peppers known for their use in hot sauces. "
            "Their intense heat and tangy flavor make them a staple in spicy cuisine.",
        "base experience": 1,
    ]),
    "artichoke": ([
        "type": "vegetable",
        "subtype": "flower",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "artichoke seed": 1
        ]),
        "default description": "Armored buds with overlapping scales protecting a tender heart. "
            "Their complex nature represents life's challenges - requiring effort "
            "to reach the sweetness hidden within.",
        "base experience": 1,
    ]),
    "broccoli": ([
        "type": "vegetable",
        "subtype": "flower",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "broccoli seed": 1
        ]),
        "default description": "Miniature forests of tightly clustered green flower buds atop thick "
            "stalks. Children's tales describe them as tiny trees where fairies "
            "shelter during rainstorms.",
        "base experience": 1,
    ]),
    "cauliflower": ([
        "type": "vegetable",
        "subtype": "flower",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "cauliflower seed": 1
        ]),
        "default description": "Pale, cloud-like clusters of undeveloped flower buds with mild "
            "flavor. Their ghostly appearance in moonlit gardens has inspired "
            "tales of spirit vegetables among superstitious farmers.",
        "base experience": 1,
    ]),
    "cucumber": ([
        "type": "vegetable",
        "subtype": "fruit",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "cucumber seed": 1
        ]),
        "default description": "Crisp, cooling cylinders with high water content and refreshing "
            "flavor. Their cooling properties make them valued by desert travelers "
            "who place slices on their eyes to soothe sun-strained vision.",
        "base experience": 1,
    ]),
    "eggplant": ([
        "type": "vegetable",
        "subtype": "fruit",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "eggplant seed": 1
        ]),
        "default description": "Glossy, deep purple fruits with spongy flesh that absorbs flavors "
            "like a magical sponge. Their royal color once restricted them to "
            "noble tables in certain ancient kingdoms.",
        "base experience": 1,
    ]),
    "okra": ([
        "type": "vegetable",
        "subtype": "fruit",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "okra seed": 1
        ]),
        "default description": "Ridged, tapered green pods containing seeds embedded in slippery "
            "mucilage. Their thickening properties are prized by alchemists "
            "creating potions that must maintain specific viscosity.",
        "base experience": 1,
    ]),
    "black peppercorn": ([
        "type": "fruit",
        "subtype": "pepper",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "black peppercorn seed": 1
        ]),
        "default description": "Small, wrinkled dark spheres with fiery heat that awakens the "
            "palate and clears the sinuses. Once worth their weight in gold, these "
            "precious spice berries have launched expeditions and toppled empires.",
        "base experience": 1,
    ]),
    "buttercup squash": ([
        "type": "vegetable",
        "subtype": "squash",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "buttercup squash seed": 1
        ]),
        "default description": "Dark green squash with distinctive cap-like protrusion and sweet, "
            "nutty orange flesh. Children hold them under chins to see golden "
            "reflections that supposedly predict coming wealth.",
        "base experience": 1,
    ]),
    "acorn squash": ([
        "type": "vegetable",
        "subtype": "squash",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "acorn squash seed": 1
        ]),
        "default description": "Oak-nut shaped squash with dark green, deeply ridged exterior and "
            "sweet golden flesh. Forest dwellers consider them gifts from tree "
            "spirits, despite growing on vines rather than branches.",
        "base experience": 1,
    ]),
    "butternut squash": ([
        "type": "vegetable",
        "subtype": "squash",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "butternut squash seed": 1
        ]),
        "default description": "Beige, bell-shaped squash with dense orange flesh and sweet, nutty "
            "flavor. Their hourglass form led to folklore about them capturing "
            "summer's warmth to release during winter cooking.",
        "base experience": 1,
    ]),
    "spaghetti squash": ([
        "type": "vegetable",
        "subtype": "squash",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "spaghetti squash seed": 1
        ]),
        "default description": "Pale yellow squash containing flesh that separates into pasta-like "
            "strands when cooked. Children's tales claim they're created by pasta "
            "sprites who hide their work inside unassuming gourds.",
        "base experience": 1,
    ]),
    "ambercup squash": ([
        "type": "vegetable",
        "subtype": "squash",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "ambercup squash seed": 1
        ]),
        "default description": "Orange-red squash with sweet, fine-grained flesh reminiscent of "
            "chestnuts. Tradition holds that leaving one on the hearth during "
            "winter solstice ensures household warmth until spring.",
        "base experience": 1,
    ]),
    "autumn cup squash": ([
        "type": "vegetable",
        "subtype": "squash",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "autumn cup squash seed": 1
        ]),
        "default description": "Deeply ribbed squash with colors that mimic falling leaves - russet, "
            "gold, and green. Eating its sweet flesh is said to prepare the body "
            "for winter's challenges and prevent seasonal melancholy.",
        "base experience": 1,
    ]),
    "banana squash": ([
        "type": "vegetable",
        "subtype": "squash",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "banana squash seed": 1
        ]),
        "default description": "Enormous, cylindrical squash that can grow to three feet long with "
            "vibrant pink-orange flesh. Their impressive size makes them fixtures "
            "in harvest competitions and abundance rituals.",
        "base experience": 1,
    ]),
    "carnival squash": ([
        "type": "vegetable",
        "subtype": "squash",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "carnival squash seed": 1
        ]),
        "default description": "Festive squash with cream, orange, and green patterns swirling across "
            "its surface. Their colorful appearance has made them traditional "
            "decorations during autumn celebrations and harvest festivals.",
        "base experience": 1,
    ]),
    "delicata squash": ([
        "type": "vegetable",
        "subtype": "squash",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "delicata squash seed": 1
        ]),
        "default description": "Oblong cream-colored squash with green stripes and delicate, edible "
            "skin. The sweet flesh tastes of honey and corn, earning them the "
            "nickname 'sweet potato squash' among chefs.",
        "base experience": 1,
    ]),
    "musquee de provence squash": ([
        "type": "vegetable",
        "subtype": "squash",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "musquee de provence squash seed": 1
        ]),
        "default description": "Magnificent flattened pumpkin with deep ribbing and dusty orange-"
            "brown skin. Their sophisticated flavor is enhanced by age, leading "
            "to beliefs that they contain accumulated wisdom.",
        "base experience": 1,
    ]),
    "gold nugget squash": ([
        "type": "vegetable",
        "subtype": "squash",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "gold nugget squash seed": 1
        ]),
        "default description": "Small, brilliant orange squash with sweet flesh and convenient "
            "single-serving size. Miners and prospectors carry them as good luck "
            "charms, believing they attract precious metals.",
        "base experience": 1,
    ]),
    "hubbard squash": ([
        "type": "vegetable",
        "subtype": "squash",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "hubbard squash seed": 1
        ]),
        "default description": "Massive, tear-shaped squash with bumpy skin in blue, green, or "
            "orange. Their enormous size and long-keeping qualities make them "
            "symbols of abundance during lean winter months.",
        "base experience": 1,
    ]),
    "sweet dumpling squash": ([
        "type": "vegetable",
        "subtype": "squash",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "sweet dumpling squash seed": 1
        ]),
        "default description": "Small, round squash with cream and green stripes that resemble "
            "wrapped candies. Their natural sweetness and perfect single-serving "
            "size have earned them a place in children's favorite meals.",
        "base experience": 1,
    ]),
    "turban squash": ([
        "type": "vegetable",
        "subtype": "squash",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "turban squash seed": 1
        ]),
        "default description": "Ornamental squash with a distinctive cap that resembles royal "
            "headwear. Their unusual appearance has created legends about "
            "mysterious foreign travelers who left enchanted seeds.",
        "base experience": 1,
    ]),
    "zucchini": ([
        "type": "vegetable",
        "subtype": "squash",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "zucchini seed": 1
        ]),
        "default description": "Slender green summer squash with tender skin and mild flavor. Their "
            "prolific growth has inspired jokes about farmers needing to lock "
            "their doors lest neighbors sneak extra zucchini inside.",
        "base experience": 1,
    ]),
    "pumpkin": ([
        "type": "vegetable",
        "subtype": "squash",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "pumpkin seed": 1
        ]),
        "default description": "Large orange squash with thick walls and central cavity filled with "
            "seeds. Carved with faces and lit from within, they ward off "
            "malevolent spirits during the thin times between seasons.",
        "base experience": 1,
    ]),
    "salt": ([
        "type": "mineral",
        "subtype": "salt",
        "crafting prerequisites": ([
            "mining":(["type":"skill", "value" : 2]),
        ]),
        "crafting materials": ([
            "rock salt": 1
        ]),
        "default description": "Crystalline white grains prized for their ability to "
            "preserve food and enhance flavor. Once so valuable it was used as "
            "currency, salt is essential to both commoners and royalty alike.",
        "base experience": 1,
    ]),
    "roasted chicken": ([
        "type": "chicken",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/food/roasting.c":(["type":"research"]),
            "cooking": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "chicken": 1,
            "salt": 1,
            "garlic": 1,
            "pepper": 1,
            "paprika": 1
        ]),
        "default description": "Golden-brown bird with crispy skin and succulent meat infused with "
            "herbs and spices. Its heavenly aroma can reportedly draw travelers "
            "home from miles away through some form of culinary magic.",
        "base experience": 5,
    ]),
    "roasted duck": ([
        "type":"duck",
        "crafting prerequisites" : ([
            "/lib/instances/research/crafting/food/roasting.c":(["type":"research"]),
            "cooking" : (["type":"skill", "value" : 3]),
        ]),
        "crafting materials" : ([
            "duck":1,
            "salt" : 1,
            "garlic" : 1,
            "pepper" : 1,
            "paprika" : 1
        ]),
        "default description": "Rich, flavorful bird with crispy skin and tender meat. Its "
        "distinctive taste has made it a favorite among nobility and "
        "adventurers alike, often served at feasts celebrating great deeds.",
        "base experience" : 5,
    ]),
    "roasted turkey": ([
        "type":"turkey",
        "crafting prerequisites" : ([
            "/lib/instances/research/crafting/food/roasting.c":(["type":"research"]),
            "cooking" : (["type":"skill", "value" : 3]),
        ]),
        "crafting materials" : ([
            "turkey":1,
            "salt" : 1,
            "garlic" : 1,
            "pepper" : 1,
            "paprika" : 1
        ]),
        "default description": "Majestic bird with golden-brown skin and tender, juicy meat. "
        "Its size and flavor make it the centerpiece of grand feasts, "
        "symbolizing abundance and gratitude.",
        "base experience" : 5,
    ]),
    "roasted goose": ([
        "type":"goose",
        "crafting prerequisites" : ([
            "/lib/instances/research/crafting/food/roasting.c":(["type":"research"]),
            "cooking" : (["type":"skill", "value" : 3]),
        ]),
        "crafting materials" : ([
            "goose":1,
            "salt" : 1,
            "garlic" : 1,
            "pepper" : 1,
            "paprika" : 1
        ]),
        "default description": "Large, succulent bird with rich, flavorful meat and crispy skin. "
        "Its robust flavor has made it a favorite for festive occasions, "
        "often served with sweet and savory accompaniments.",
        "base experience" : 5,
    ]),
    "roasted quail": ([
        "type":"quail",
        "crafting prerequisites" : ([
            "/lib/instances/research/crafting/food/roasting.c":(["type":"research"]),
            "cooking" : (["type":"skill", "value" : 3]),
        ]),
        "crafting materials" : ([
            "quail":1,
            "salt" : 1,
            "garlic" : 1,
            "pepper" : 1,
            "paprika" : 1
        ]),
        "default description": "Delicate, tender bird with subtle flavor and crispy skin. Its "
        "small size makes it a luxurious treat, often served at intimate "
        "dinners or as part of elaborate feasts.",
        "base experience" : 5,
    ]),
    "roasted pheasant": ([
        "type":"pheasant",
        "crafting prerequisites" : ([
            "/lib/instances/research/crafting/food/roasting.c":(["type":"research"]),
            "cooking" : (["type":"skill", "value" : 3]),
        ]),
        "crafting materials" : ([
            "pheasant":1,
            "salt" : 1,
            "garlic" : 1,
            "pepper" : 1,
            "paprika" : 1
        ]),
        "default description": "Elegant bird with tender, flavorful meat and crispy skin. Its "
        "refined taste has made it a favorite among nobility, often served "
        "with rich sauces and seasonal vegetables.",
        "base experience" : 5,
    ]),
    "roasted rabbit": ([
        "type":"rabbit",
        "crafting prerequisites" : ([
            "/lib/instances/research/crafting/food/roasting.c":(["type":"research"]),
            "cooking" : (["type":"skill", "value" : 3]),
        ]),
        "crafting materials" : ([
            "rabbit":1,
            "salt" : 1,
            "garlic" : 1,
            "pepper" : 1,
            "paprika" : 1
        ]),
        "default description": "Tender, succulent meat with a delicate flavor and crispy skin. "
        "Its lightness makes it a popular choice for spring feasts, often "
        "served with fresh herbs and seasonal vegetables.",
        "base experience" : 5,
    ]),
    "roasted lamb": ([
        "type":"lamb",
        "crafting prerequisites" : ([
            "/lib/instances/research/crafting/food/roasting.c":(["type":"research"]),
            "cooking" : (["type":"skill", "value" : 3]),
        ]),
        "crafting materials" : ([
            "lamb":1,
            "salt" : 1,
            "garlic" : 1,
            "pepper" : 1,
            "paprika" : 1
        ]),
        "default description": "Tender, flavorful meat with a rich aroma and crispy skin. Its "
        "distinctive taste has made it a favorite for festive occasions, "
        "often served with mint sauce or roasted vegetables.",
        "base experience" : 5,
    ]),
    "roasted pork": ([
        "type":"pork",
        "crafting prerequisites" : ([
            "/lib/instances/research/crafting/food/roasting.c":(["type":"research"]),
            "cooking" : (["type":"skill", "value" : 3]),
        ]),
        "crafting materials" : ([
            "pork":1,
            "salt" : 1,
            "garlic" : 1,
            "pepper" : 1,
            "paprika" : 1
        ]),
        "default description": "Juicy, succulent meat with a crispy, caramelized exterior. Its "
        "savory flavor has made it a staple at feasts and celebrations, often "
        "served with applesauce or roasted root vegetables.",
        "base experience" : 5,
    ]),
    "roasted beef": ([
        "type":"beef",
        "crafting prerequisites" : ([
            "/lib/instances/research/crafting/food/roasting.c":(["type":"research"]),
            "cooking" : (["type":"skill", "value" : 3]),
        ]),
        "crafting materials" : ([
            "beef":1,
            "salt" : 1,
            "garlic" : 1,
            "pepper" : 1,
            "paprika" : 1
        ]),
        "default description": "Rich, hearty meat with a deep, savory flavor and tender texture. "
        "Its robust taste has made it a favorite for winter feasts, often "
        "served with rich gravies and roasted vegetables.",
        "base experience" : 5,
    ]),
    "roasted venison": ([
        "type":"venison",
        "crafting prerequisites" : ([
            "/lib/instances/research/crafting/food/roasting.c":(["type":"research"]),
            "cooking" : (["type":"skill", "value" : 3]),
        ]),
        "crafting materials" : ([
            "venison":1,
            "salt" : 1,
            "garlic" : 1,
            "pepper" : 1,
            "paprika" : 1
        ]),
        "default description": "Lean, flavorful meat with a rich, gamey taste and tender texture. "
        "Its distinctive flavor has made it a favorite among hunters, often "
        "served with berry sauces or roasted root vegetables.",
        "base experience" : 5,
    ]),
    "wheat bread": ([
        "type": "bread",
        "subtype": "wheat",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/food/baking.c":(["type":"research"]),
            "cooking": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "wheat flour": 2,
            "water": 1,
            "salt": 1,
            "yeast": 1
        ]),
        "default description": "Golden-crusted loaves with a hearty texture and the wholesome aroma "
            "of baked grain. The soft, airy interior yields to gentle pressure, "
            "releasing the comforting scent that transforms humble grain into sustenance.",
        "base experience": 3,
    ]),
    "rye bread": ([
        "type":"bread",
        "subtype" : "rye",
        "crafting prerequisites" : ([
            "/lib/instances/research/crafting/food/baking.c":(["type":"research"]),
            "cooking" : (["type":"skill", "value" : 3]),
        ]),
        "crafting materials" : ([
            "rye flour":2,
            "water" : 1,
            "salt" : 1,
            "yeast" : 1
        ]),
        "default description": "Dense, dark loaves with a slightly sour aroma and chewy texture. "
        "Their robust flavor pairs well with hearty stews and smoked meats, "
        "making them staples in northern kitchens.",
        "base experience" : 3,
    ]),
    "barley bread": ([
        "type":"bread",
        "subtype" : "barley",
        "crafting prerequisites" : ([
            "/lib/instances/research/crafting/food/baking.c":(["type":"research"]),
            "cooking" : (["type":"skill", "value" : 3]),
        ]),
        "crafting materials" : ([
            "barley flour":2,
            "water" : 1,
            "salt" : 1,
            "yeast" : 1
        ]),
        "default description": "Nutty, slightly sweet loaves with a coarse texture and hearty "
        "flavor. Their rustic appearance and wholesome aroma evoke images of "
        "ancient fields where barley was first cultivated by early farmers.",
        "base experience" : 3,
    ]),
    "oat bread": ([
        "type":"bread",
        "subtype" : "oat",
        "crafting prerequisites" : ([
            "/lib/instances/research/crafting/food/baking.c":(["type":"research"]),
            "cooking" : (["type":"skill", "value" : 3]),
        ]),
        "crafting materials" : ([
            "oat flour":2,
            "water" : 1,
            "salt" : 1,
            "yeast" : 1
        ]),
        "default description": "Soft, golden loaves with a slightly sweet aroma and tender crumb. "
        "Their wholesome flavor and light texture make them perfect for "
        "breakfast spreads or as a base for hearty sandwiches.",
        "base experience" : 3,
    ]),
    "cornbread": ([
        "type":"bread",
        "subtype" : "corn",
        "crafting prerequisites" : ([
            "/lib/instances/research/crafting/food/baking.c":(["type":"research"]),
            "cooking" : (["type":"skill", "value" : 3]),
        ]),
        "crafting materials" : ([
            "cornmeal":2,
            "water" : 1,
            "salt" : 1,
            "baking powder" : 1
        ]),
        "default description": "Golden, crumbly loaves with a sweet, buttery aroma. Their "
        "moist texture and slightly gritty bite evoke memories of summer "
        "picnics and family gatherings around the hearth.",
        "base experience" : 3,
    ]),
    "sourdough bread": ([
        "type":"bread",
        "subtype" : "sourdough",
        "crafting prerequisites" : ([
            "/lib/instances/research/crafting/food/baking.c":(["type":"research"]),
            "cooking" : (["type":"skill", "value" : 3]),
        ]),
        "crafting materials" : ([
            "sourdough starter":1,
            "water" : 1,
            "salt" : 1,
            "flour" : 2
        ]),
        "default description": "Crusty, tangy loaves with a chewy crust and airy interior. Their "
        "distinctive sour aroma and complex flavor profile make them a "
        "favorite among artisan bakers and culinary enthusiasts.",
        "base experience" : 3,
    ]),
    "sweet yellow pepper": ([
        "type": "fruit",
        "subtype": "pepper",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "crafting materials" : ([
            "sweet yellow pepper seed":1
        ]),
        "default description": "Bright yellow peppers with a sweet, fruity flavor and crisp texture. "
        "Their sunny hue is said to bring warmth and joy to any dish, "
        "making them popular in both cooking and decoration.",
        "base experience": 1,
    ]),
    "basil": ([
        "type": "herb",
        "subtype": "basil",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "basil seed": 1
        ]),
        "default description": "Aromatic green leaves with complex notes of pepper, mint, and "
            "anise. This royal herb is said to open the heart and mind to love's "
            "possibilities when placed beneath a pillow during full moons.",
        "base experience": 1,
    ]),
    "alder catkin": ([
        "type": "seed",
        "subtype": "alder",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Long, dangling clusters of tiny flowers from alder trees that "
            "release golden pollen. These early spring harbingers are collected "
            "by woodland witches for fertility and manifestation spells.",
        "base experience": 1,
    ]),
    "aspen catkin": ([
        "type": "seed",
        "subtype": "alder",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Drooping clusters of silver-gray flowers that emerge before aspen "
            "leaves unfurl. Their constant trembling is said to be the trees "
            "whispering secrets from the underworld to the living.",
        "base experience": 1,
    ]),
    "willow catkin": ([
        "type": "seed",
        "subtype": "willow",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Soft, fuzzy flower clusters that appear like silver-furred "
            "caterpillars on willow branches. Water sprites are said to use them "
            "as boats when traveling upstream against currents.",
        "base experience": 1,
    ]),
    "cottonwood catkin": ([
        "type": "seed",
        "subtype": "cottonwood",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Dangling red-brown flower clusters that mature into seeds surrounded "
            "by white fluff. The floating seeds create summer snowstorms that "
            "some believe carry messages between distant lovers.",
        "base experience": 1,
    ]),
    "poplar catkin": ([
        "type": "seed",
        "subtype": "poplar",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Long, hanging flower clusters that release seeds attached to silky "
            "hairs. Children catch the floating seeds to make wishes, believing "
            "each tuft carries hopes to the sky spirits.",
        "base experience": 1,
    ]),
    "paper birch catkin": ([
        "type": "seed",
        "subtype": "paper birch",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Slender, cylindrical flower clusters from trees with distinctive "
            "white bark. Druids collect them during spring equinox, believing they "
            "contain the awakening energy of the returning sun.",
        "base experience": 1,
    ]),
    "birch catkin": ([
        "type": "seed",
        "subtype": "birch",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Pendulous golden-brown flower clusters that release tiny winged "
            "seeds. Folklore claims they contain the souls of ancient forest "
            "guardians who watch over younger trees and plants.",
        "base experience": 1,
    ]),
    "ironwood catkin": ([
        "type": "seed",
        "subtype": "ironwood",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Stiff flowering clusters from exceptionally hard-wooded trees. Their "
            "unusual weight and density leads smiths to burn them as offerings "
            "when forging weapons intended for heroes.",
        "base experience": 1,
    ]),
    "yew cone": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Small, modified berries with poisonous seeds covered by sweet red "
            "flesh. Yew's association with both death and immortality makes these "
            "seeds powerful components in certain dark rituals.",
        "base experience": 1,
    ]),
    "pine cone": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Woody, spiral-arranged seed containers with scales that open when "
            "mature. Their perfect mathematical patterns have been studied by "
            "scholars seeking to understand nature's hidden order.",
        "base experience": 1,
    ]),
    "fir cone": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Upright cylindrical cones with distinctive bracts between scales. "
            "Mountain peoples burn them during winter ceremonies, believing their "
            "smoke carries prayers directly to sky deities.",
        "base experience": 1,
    ]),
    "spruce cone": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Pendant cones with thin, flexible scales that hang from spruce "
            "branches. Their resinous aroma is believed to clear negative energies "
            "when burned during house-cleansing rituals.",
        "base experience": 1,
    ]),
    "redwood cone": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Surprisingly small seed cones from the world's tallest trees. "
            "The contrast between tiny seed and massive mature tree makes them "
            "symbols of potential and the power of patient growth.",
        "base experience": 1,
    ]),
    "hemlock cone": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Tiny, delicate cones no larger than a fingertip from coniferous "
            "trees. Despite sharing a name with poisonous herbs, these cones "
            "represent resilience in ancient woodland symbolism.",
        "base experience": 1,
    ]),
    "cypress cone": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Woody, spherical structures with angular scales that release "
            "tiny winged seeds. Their association with longevity makes them "
            "traditional gifts for newborns in some forest communities.",
        "base experience": 1,
    ]),
    "cedar cone": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Barrel-shaped cones with overlapping scales infused with aromatic "
            "oils. Their distinctive scent is believed to enhance meditation and "
            "communication with ancient nature spirits.",
        "base experience": 1,
    ]),
    "ash samara": ([
        "type": "seed",
        "subtype": "ash",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Single-winged seeds that spin like helicopter blades when falling "
            "from ash trees. Children throw them into the air, believing the "
            "spinning direction predicts their future prosperity.",
        "base experience": 1,
    ]),
    "elm samara": ([
        "type": "seed",
        "subtype": "elm",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Round, flat seeds encircled by papery wings that catch breeze "
            "currents. These gently floating seeds inspired tales of nature "
            "spirits using them as tiny boats through air rivers.",
        "base experience": 1,
    ]),
    "maple samara": ([
        "type": "seed",
        "subtype": "maple",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Twin-winged seeds that spin gracefully through the air like dancing "
            "fairies. Children stick them on their noses, claiming this grants "
            "them temporary ability to speak with trees.",
        "base experience": 1,
    ]),    
    "sugar maple samara": ([
        "type": "seed",
        "subtype": "sugar maple",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Paired winged seeds from trees whose sweet sap becomes maple "
            "syrup. Their graceful autumn flight is said to choreograph the "
            "complex dance of coming winter winds.",
        "base experience": 1,
    ]),    
    "rosewood seed": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Dark seeds from trees valued for their fragrant, beautiful wood. "
            "Master instrument makers plant one seed for each tree harvested, "
            "singing specific melodies to encourage harmonious growth.",
        "base experience": 1,
    ]),    
    "purple heart seed pod": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Elongated pods containing seeds from purple-hearted tropical "
            "trees. Their unusual violet heartwood is mirrored in the pods' "
            "purplish tinge when they're ready for harvest.",
        "base experience": 1,
    ]),    
    "mesquite seed pod": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Twisted, tan pods containing seeds surrounded by sweet pulp. Desert "
            "nomads crush them into nutritious flour that can sustain travelers "
            "through the harshest sand-scoured journeys.",
        "base experience": 1,
    ]),    
    "marblewood seed pod": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Hardy pods with striped patterns mirroring the striking grain of "
            "marblewood timber. Woodcarvers collect them as talismans, believing "
            "they enhance artistic vision and steady hands.",
        "base experience": 1,
    ]),    
    "lacewood seed pod": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Delicate pods with lace-like patterns containing seeds from trees "
            "with distinctive flecked grain. Their intricate design inspires "
            "embroiderers and lacemakers seeking natural patterns.",
        "base experience": 1,
    ]),    
    "koa seed pod": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Crescent-shaped pods from the sacred Hawaiian koa tree. Island "
            "tradition holds that these seeds should be gathered only after "
            "singing gratitude songs to the parent tree.",
        "base experience": 1,
    ]),    
    "ebony seed pod": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Unusual pods with ghost-pale exteriors containing seeds that will "
            "grow into trees with midnight-black heartwood. Their stark contrast "
            "symbolizes hidden potential in many cultures.",
        "base experience": 1,
    ]),    
    "bubinga seed pod": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Curved pods containing seeds from African trees with pinkish-red "
            "wood. Tradition claims that carrying these pods encourages dreams "
            "that reveal creative solutions to waking problems.",
        "base experience": 1,
    ]),    
    "black locust seed pod": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Flat, dark brown pods containing rows of extremely hard seeds. "
            "Their remarkable durability led ancient peoples to use them as "
            "fortune-telling devices in divination rituals.",
        "base experience": 1,
    ]),    
    "bloodwood seed": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Deep crimson seeds from trees whose cut timber appears to 'bleed' "
            "red sap. Warriors sometimes carry these seeds, believing they "
            "connect them to ancestral strength during battle.",
        "base experience": 1,
    ]),    
    "hickory globose": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Round seed structures with thick, woody husks protecting sweet "
            "kernels inside. Their hard exteriors represent the necessity of "
            "persistence to reach life's sweetest rewards.",
        "base experience": 1,
    ]),    
    "buckeye globose": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Glossy brown seeds with distinctive pale circular scars resembling "
            "eyes. Their uncanny eye-like appearance led to beliefs they could "
            "ward off the evil eye and protect from dark magic.",
        "base experience": 1,
    ]),    
    "kingwood seed pod": ([
        "type": "seed",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Regal pods containing seeds from trees with purple-streaked timber. "
            "Their connection to royalty makes them sought after components in "
            "rituals designed to attract power and authority.",
        "base experience": 1,
    ]),    
    "maple sap": ([
        "type": "sap",
        "subtype": "maple",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Clear, slightly sweet liquid that flows from maple trees in early "
            "spring. This liquid sunshine requires patient reduction to transform "
            "into the liquid gold known as maple syrup.",
        "base experience": 1,
    ]),    
    "winesap apple": ([
        "type": "fruit",
        "subtype": "apple",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Deep red apples with spicy-sweet flesh and subtle wine-like notes. "
            "Their rich flavor has inspired tales of orchards where fruit "
            "ferments while still hanging from branches.",
        "base experience": 1,
    ]),
    "red apple": ([
        "type": "fruit",
        "subtype": "apple",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Bright crimson fruits with crisp white flesh and balanced sweet-"
            "tart flavor. Old wives' tales claim these apples keep healers away "
            "when eaten daily, though healers dispute this.",
        "base experience": 1,
    ]),
    "mcintosh apple": ([
        "type": "fruit",
        "subtype": "apple",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Aromatic red and green apples with tender white flesh and tangy-"
            "sweet juice. Their distinctive scent is so alluring that orchardists "
            "must guard against fruit-loving forest spirits.",
        "base experience": 1,
    ]),
    "honeycrisp apple": ([
        "type": "fruit",
        "subtype": "apple",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Exceptionally crisp, juicy apples with perfect balance of sweetness "
            "and acidity. Legend claims they were created when a beekeeper's "
            "hive swarmed through a blossoming orchard.",
        "base experience": 1,
    ]),
    "green apple": ([
        "type": "fruit",
        "subtype": "apple",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Tart, bright green fruits with firm flesh and mouth-puckering "
            "acidity. They're favored for baking and preserves, where heat and "
            "sugar transform their sharpness into complex flavors.",
        "base experience": 1,
    ]),
    "golden apple": ([
        "type": "fruit",
        "subtype": "apple",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Sunshine-yellow apples with smooth skin and honey-sweet flesh. In "
            "fairy tales, these apples grant eternal youth when grown in "
            "enchanted gardens tended by mysterious silver-haired women.",
        "base experience": 1,
    ]),
    "cortland apple": ([
        "type": "fruit",
        "subtype": "apple",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Snow-white fleshed apples with bright red skin and unusual "
            "resistance to browning when cut. Some believe this quality "
            "represents incorruptibility and protection against decay.",
        "base experience": 1,
    ]),
    "ambrosia apple": ([
        "type": "fruit",
        "subtype": "apple",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Rosy pink and cream-colored apples with exceptionally sweet, "
            "honeyed flavor. Their name references the food of the gods, hinting "
            "at divine origin and transcendent taste.",
        "base experience": 1,
    ]),
    "crabapple": ([
        "type": "fruit",
        "subtype": "apple",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Small, tart fruits with vibrant colors ranging from yellow to "
            "deep red. Though too sour for direct eating, they transform into "
            "jewel-like preserves with unique floral undertones.",
        "base experience": 1,
    ]),
    "apple": ([
        "type": "fruit",
        "subtype": "apple",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Round fruits with crisp flesh and a perfect balance of sweetness "
            "and acidity. These quintessential fruits have symbolized knowledge, "
            "temptation, and immortality across many cultures.",
        "base experience": 1,
    ]),
    "willow bark": ([
        "type": "bark",
        "subtype": "willow",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Flexible strips of bark containing natural pain-relieving compounds. "
            "Healers have used this remarkable substance for centuries to reduce "
            "fever and ease various suffering.",
        "base experience": 1,
    ]),
    "grape": ([
        "type": "fruit",
        "subtype": "grape",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Juicy berries growing in clusters, ranging from pale green to "
            "deep purple. Beyond their sweet flavor, they transform through "
            "fermentation into wine - liquid poetry in a glass.",
        "base experience": 1,
    ]),
    "plum": ([
        "type": "fruit",
        "subtype": "plum",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Smooth-skinned stone fruits with juicy flesh in shades from yellow "
            "to black-purple. Their sweet-tart balance makes them perfect for "
            "eating fresh or transforming into preserves.",
        "base experience": 1,
    ]),
    "pear": ([
        "type": "fruit",
        "subtype": "pear",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Bell-shaped fruits with buttery flesh and delicate, aromatic "
            "sweetness. Their elegant form has inspired artists and poets "
            "to meditate on the perfect union of beauty and function.",
        "base experience": 1,
    ]),
    "apricot": ([
        "type": "fruit",
        "subtype": "apricot",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Velvety golden fruits with tender flesh and honeyed sweetness "
            "balanced by slight tartness. Ancient peoples considered them "
            "emblems of fertility and feminine beauty.",
        "base experience": 1,
    ]),
    "peach": ([
        "type": "fruit",
        "subtype": "peach",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Fuzzy-skinned stone fruits with succulent, aromatic flesh in "
            "shades from white to deep orange. Their sensual qualities and "
            "sweet juice have made them symbols of desire and indulgence.",
        "base experience": 1,
    ]),
    "persimmon": ([
        "type": "fruit",
        "subtype": "persimmon",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Bright orange fruits that must fully ripen to transform from "
            "astringent to honey-sweet. Folklore claims their seed patterns "
            "predict winter weather in the coming year.",
        "base experience": 1,
    ]),
    "nectarine": ([
        "type": "fruit",
        "subtype": "nectarine",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Smooth-skinned relatives of peaches with firm, aromatic flesh. "
            "Their name derives from 'nectar,' the mythical drink of gods, "
            "hinting at their divine sweetness.",
        "base experience": 1,
    ]),
    "mulberry": ([
        "type": "fruit",
        "subtype": "mulberry",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Compound berries resembling blackberries in various shades from "
            "white to deep purple. Their juice stains so persistently that dyers "
            "use it for fabrics intended to hold magic spells.",
        "base experience": 1,
    ]),
    "montmorency cherry": ([
        "type": "fruit",
        "subtype": "cherry",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Bright red sour cherries with clear juice and tart flavor perfect "
            "for pies and preserves. Their vibrant acidity is believed to "
            "awaken the appetite and stimulate digestion.",
        "base experience": 1,
    ]),
    "choke cherry": ([
        "type": "fruit",
        "subtype": "cherry",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Small, astringent cherries that grow in clusters on wild trees. "
            "Though too bitter raw, cooking transforms them into prized preserves "
            "with complex flavor and ruby-red color.",
        "base experience": 1,
    ]),
    "black cherry": ([
        "type": "fruit",
        "subtype": "cherry",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Deep purple-black cherries with intensely sweet flesh and staining "
            "juice. Their wood is prized by furniture makers, who claim the trees "
            "absorb dreams through their fruit.",
        "base experience": 1,
    ]),
    "bing cherry": ([
        "type": "fruit",
        "subtype": "cherry",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Large, heart-shaped cherries with mahogany-colored flesh and rich, "
            "sweet flavor. Their perfect balance of sugar and subtle acidity "
            "makes them the standard by which all cherries are judged.",
        "base experience": 1,
    ]),
    "cherry": ([
        "type": "fruit",
        "subtype": "cherry",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Bright red stone fruits with juicy flesh and single hard pit. "
            "Their brief seasonal appearance makes them symbols of life's "
            "fleeting pleasures and beauty's impermanence.",
        "base experience": 1,
    ]),
    "malorn fruit": ([
        "type": "fruit",
        "subtype": "malorn",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Mythical silver-veined fruits with ethereal flavor that changes "
            "based on the eater's deepest desires. Ancient texts claim they "
            "once grew only in enchanted groves guarded by fey creatures.",
        "base experience": 1,
    ]),
    "magnolia fruit": ([
        "type": "fruit",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Cone-like aggregates of follicles that emerge from magnificent "
            "flowering trees. Though inedible to humans, birds treasure the "
            "bright red seeds within, spreading them far and wide.",
        "base experience": 1,
    ]),
    "lilac fruit": ([
        "type": "fruit",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Small, dry capsules that develop after lilac's fragrant flowers "
            "fade. Though not meant for eating, these seed pods are collected "
            "as amulets that supposedly protect against melancholy.",
        "base experience": 1,
    ]),
    "holly fruit": ([
        "type": "fruit",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Bright red berries that persist through winter on glossy-leaved "
            "evergreen shrubs. Though poisonous to humans, their beauty against "
            "snow makes them symbols of endurance and protection.",
        "base experience": 1,
    ]),
    "buckthorn fruit": ([
        "type": "fruit",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Purple-black berries with powerful purgative properties, growing "
            "on thorny shrubs. While dangerous to eat, dyers prize them for "
            "creating vibrant yellows and greens in textiles.",
        "base experience": 1,
    ]),
    "dogwood fruit": ([
        "type": "fruit",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Bright red berries that appear after the tree's distinctive "
            "four-petaled flowers fade. Birds feast on these fruits while humans "
            "admire their vivid color against autumn foliage.",
        "base experience": 1,
    ]),
    "teak fruit": ([
        "type": "fruit",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Papery, inflated capsules containing seeds from one of the world's "
            "most valuable timber trees. Shipbuilders collect them as talismans "
            "for vessels intended to weather fierce storms.",
        "base experience": 1,
    ]),
    "sycamore fruit": ([
        "type": "fruit",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Spiky balls containing tiny seeds with attached wings for wind "
            "dispersal. Children collect and dry these curious spheres for "
            "decorations and imaginative play scenarios.",
        "base experience": 1,
    ]),
    "mahogany fruit": ([
        "type": "fruit",
        "subtype": "inedible",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Woody capsules that split into five sections when mature, from "
            "trees with rich reddish-brown timber. Cabinet makers carry these "
            "seed pods as symbols of their craft's noble heritage.",
        "base experience": 1,
    ]),
    "malorn flower": ([
        "type": "flower",
        "subtype": "malorn",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Mythical blossoms with petals that shift color with moonlight and "
            "mood. Their subtle fragrance reportedly reveals different scents to "
            "each person based on their heart's deepest desires.",
        "base experience": 1,
    ]),
    "magnolia flower": ([
        "type": "flower",
        "subtype": "magnolia",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Large, primitive blossoms with thick waxy petals in cream, pink, "
            "or white. Their intoxicating lemony fragrance has inspired poets "
            "and perfumers for centuries across many civilizations.",
        "base experience": 1,
    ]),
    "lilac flower": ([
        "type": "flower",
        "subtype": "lilac",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Fragrant clusters of tiny four-petaled blossoms in shades of "
            "purple, white, or pink. Their distinctive scent evokes memories so "
            "powerfully that some claim they can access past lives.",
        "base experience": 1,
    ]),
    "walnut": ([
        "type": "nut",
        "subtype": "walnut",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Brain-like kernels encased in hard shells and green husks that "
            "stain fingers brown. Their resemblance to the human brain led "
            "ancient healers to prescribe them for mental acuity.",
        "base experience": 1,
    ]),
    "pine nut": ([
        "type": "nut",
        "subtype": "pine nut",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Small, elongated seeds harvested from certain pine cones with "
            "rich, buttery flavor. Their labor-intensive collection makes them "
            "treasured ingredients in celebratory dishes.",
        "base experience": 1,
    ]),
    "acorn": ([
        "type": "nut",
        "subtype": "acorn",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Oak tree seeds with distinctive caps and bitter kernels that "
            "require processing to remove tannins before eating. Their "
            "abundance led ancient peoples to develop methods to utilize them.",
        "base experience": 1,
    ]),
    "pecan": ([
        "type": "nut",
        "subtype": "pecan",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Sweet, buttery nuts with distinctive ridged shells and oil-rich "
            "kernels. Southern folklore claims that pecan trees planted near "
            "homes attract prosperity and good fortune.",
        "base experience": 1,
    ]),
    "almond": ([
        "type": "nut",
        "subtype": "almond",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Elongated kernels wrapped in papery brown skins and enclosed in "
            "woody shells. Their delicate flavor and versatility have made them "
            "treasured ingredients across many cultures.",
        "base experience": 1,
    ]),
    "beech nut": ([
        "type": "nut",
        "subtype": "beech",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Small, triangular nuts enclosed in spiny husks from majestic "
            "forest trees. Though tiny, their sweet flavor makes them worth the "
            "effort of collection for forest dwellers.",
        "base experience": 1,
    ]),
    "basswood nut": ([
        "type": "nut",
        "subtype": "basswood",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Small, hard-shelled nuts attached to distinctive wing-like bracts "
            "from fragrant-flowering trees. Though rarely eaten by humans, "
            "woodland creatures gather them as essential winter provisions.",
        "base experience": 1,
    ]),
    "sage": ([
        "type": "herb",
        "subtype": "sage",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "sage seed": 1
        ]),
        "default description": "Velvety gray-green leaves with earthy, slightly peppery flavor. "
            "Long revered for its purifying properties, burning sage is believed to "
            "cleanse spaces of malevolent spirits and enhance wisdom.",
        "base experience": 1,
    ]),
    "rosemary": ([
        "type": "herb",
        "subtype": "rosemary",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "rosemary cutting": 1
        ]),
        "default description": "Needle-like leaves with intense pine-like fragrance and resinous "
            "flavor. Students wear sprigs in their hair during examinations, as the "
            "herb is said to strengthen memory and mental clarity.",
        "base experience": 1,
    ]),
    "thyme": ([
        "type": "herb",
        "subtype": "thyme",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "thyme seed": 1
        ]),
        "default description": "Tiny, aromatic leaves growing on slender stems with a warm, "
            "slightly minty flavor. Sprigs placed beneath pillows ward off "
            "nightmares and ensure restful sleep free from dark visitations.",
        "base experience": 1,
    ]),
    "mint": ([
        "type": "herb",
        "subtype": "mint",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "mint cutting": 1
        ]),
        "default description": "Bright green serrated leaves with refreshing cooling sensation and "
            "sweet flavor. Its invigorating scent is believed to awaken the mind, "
            "while its spreading nature symbolizes abundant prosperity.",
        "base experience": 1,
    ]),
    "dill": ([
        "type": "herb",
        "subtype": "dill",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "dill seed": 1
        ]),
        "default description": "Feathery fronds with delicate anise-like flavor and subtle "
            "sweetness. Old wives claim that carrying dill seeds protects against "
            "witchcraft and calms colicky infants when brewed as tea.",
        "base experience": 1,
    ]),
    "parsley": ([
        "type": "herb",
        "subtype": "parsley",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "parsley seed": 1
        ]),
        "default description": "Bright green curled or flat leaves with fresh, slightly peppery "
            "taste. Once believed to have sprung from the blood of heroes, it's now "
            "used to cleanse palates and garnish feasts at noble tables.",
        "base experience": 1,
    ]),
    "chamomile": ([
        "type": "herb",
        "subtype": "chamomile",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "chamomile seed": 1
        ]),
        "default description": "Daisy-like flowers with apple-scented blossoms and calming "
            "properties. Mothers brew it into tea for restless children, while "
            "healers prescribe it for those troubled by anxious thoughts.",
        "base experience": 1,
    ]),
    "lavender": ([
        "type": "herb",
        "subtype": "lavender",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "lavender seed": 1
        ]),
        "default description": "Slender purple flower spikes with intensely aromatic oils and "
            "subtle flavor. Its soothing scent permeates linens of nobility, while "
            "common folk tuck sprigs into clothes to repel moths.",
        "base experience": 1,
    ]),
    "marjoram": ([
        "type": "herb",
        "subtype": "marjoram",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "marjoram seed": 1
        ]),
        "default description": "Delicate oval leaves with sweet, pine-like aroma and mild flavor. "
            "Young maidens place sprigs under their pillows to dream of future "
            "spouses, while cooks use it to flavor meats and stews.",
        "base experience": 1,
    ]),
    "oregano": ([
        "type": "herb",
        "subtype": "oregano",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "oregano seed": 1
        ]),
        "default description": "Small, pungent leaves with robust, slightly bitter flavor and "
            "earthy aroma. Soldiers carry sprigs for protection in battle, while "
            "healers use it to ward off respiratory ailments.",
        "base experience": 1,
    ]),
    "hyssop": ([
        "type": "herb",
        "subtype": "hyssop",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "hyssop seed": 1
        ]),
        "default description": "Spiky blue-purple flowers with minty-bitter flavor and strong "
            "scent. Used in ritual purification ceremonies and hung in homes to "
            "protect against plague and evil influences.",
        "base experience": 1,
    ]),
    "borage": ([
        "type": "herb",
        "subtype": "borage",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "borage seed": 1
        ]),
        "default description": "Hairy leaves and star-shaped blue flowers with cucumber-like "
            "flavor. Knights drink borage-infused wine before battle, believing it "
            "instills courage and fortitude in the face of danger.",
        "base experience": 1,
    ]),
    "clary sage": ([
        "type": "herb",
        "subtype": "clary sage",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "clary sage seed": 1
        ]),
        "default description": "Broad, fuzzy leaves and tall lavender-white flower spikes with "
            "musky aroma. Brewers add it to ales to increase potency, while seers "
            "burn it to enhance visions and prophetic dreams.",
        "base experience": 1,
    ]),
    "comfrey": ([
        "type": "herb",
        "subtype": "comfrey",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "comfrey root": 1
        ]),
        "default description": "Broad, hairy leaves and bell-shaped flowers with remarkable "
            "healing properties. Country folk call it 'knitbone' for its ability to "
            "speed the mending of broken bones and torn flesh.",
        "base experience": 1,
    ]),
    "rue": ([
        "type": "herb",
        "subtype": "rue",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "rue seed": 1
        ]),
        "default description": "Bluish-green aromatic leaves with bitter, acrid taste and strong "
            "scent. Judges carry sprigs to ward off disease in courtrooms, while "
            "witches use it to strengthen second sight and dispel curses.",
        "base experience": 1,
    ]),
    "angelica": ([
        "type": "herb",
        "subtype": "angelica",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "angelica seed": 1
        ]),
        "default description": "Tall stems with umbrella-like clusters of white flowers and "
            "celery-like aroma. Said to have been revealed by an archangel as "
            "protection against plague and evil spirits.",
        "base experience": 1,
    ]),
    "coriander": ([
        "type": "herb",
        "subtype": "coriander",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "coriander seed": 1
        ]),
        "default description": "Feathery leaves and round aromatic seeds with citrus-like flavor. "
            "Its seeds, added to wine, are believed to stimulate passion, while the "
            "leaves are used in love potions and charms.",
        "base experience": 1,
    ]),
    "tansy": ([
        "type": "herb",
        "subtype": "tansy",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "tansy seed": 1
        ]),
        "default description": "Feathery leaves and button-like yellow flowers with strong, "
            "camphor-like aroma. Placed in shoes to prevent fever and laid with the "
            "dead to aid their journey to the afterlife.",
        "base experience": 1,
    ]),
    "chervil": ([
        "type": "herb",
        "subtype": "chervil",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "chervil seed": 1
        ]),
        "default description": "Delicate, fern-like leaves with subtle anise flavor and aroma. "
            "Gathered on Midsummer's Day to bring good luck and happiness, while "
            "healers use it to purify blood and lift spirits.",
        "base experience": 1,
    ]),
    "sorrel": ([
        "type": "herb",
        "subtype": "sorrel",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "sorrel seed": 1
        ]),
        "default description": "Arrow-shaped leaves with bright, lemony sourness and tart flavor. "
            "Used to quench thirst during summer harvests and believed to cleanse "
            "the blood of winter's stagnation each spring.",
        "base experience": 1,
    ]),
    "tarragon": ([
        "type": "herb",
        "subtype": "tarragon",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "tarragon cutting": 1
        ]),
        "default description": "Slender, aromatic leaves with distinctive anise-like flavor and "
            "subtle bitterness. Court physicians recommend it for poor digestion, "
            "while cooks use it to enhance poultry and fish dishes.",
        "base experience": 1,
    ]),
    "yarrow": ([
        "type": "herb",
        "subtype": "yarrow",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "yarrow seed": 1
        ]),
        "default description": "Feathery leaves and flat clusters of tiny white flowers with "
            "subtle spicy scent. Battlefield healers use it to stanch bleeding, "
            "while diviners cast its stalks to glimpse future events.",
        "base experience": 1,
    ]),
    "alecost": ([
        "type": "herb",
        "subtype": "alecost",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "alecost cutting": 1
        ]),
        "default description": "Long, serrated aromatic leaves with balsamic mint-like flavor. "
            "Brewers add it to ales before hops became common, while housewives "
            "place it among linens to deter moths and impart fragrance.",
        "base experience": 1,
    ]),
    "wormwood": ([
        "type": "herb",
        "subtype": "wormwood",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "wormwood seed": 1
        ]),
        "default description": "Silver-gray feathery leaves with intensely bitter flavor and "
            "strong aroma. Healers use it against intestinal parasites, while "
            "travelers carry sprigs to ward off exhaustion on long journeys.",
        "base experience": 1,
    ]),
    "mugwort": ([
        "type": "herb",
        "subtype": "mugwort",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),        
        "crafting materials": ([
            "mugwort seed": 1
        ]),
        "default description": "Dark green leaves with silvery undersides and spicy, slightly "
            "bitter aroma. Placed in footwear to prevent fatigue, and burned by "
            "seers who seek prophetic dreams and spiritual visions.",
        "base experience": 1,
    ]),
    "chestnut nut": ([
        "type": "nut",
        "subtype": "chestnut",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Glossy brown nuts encased in spiny burrs with sweet, starchy "
            "flesh. These nutritious kernels were staples for ancient peoples "
            "and remain prized for their rich, nutty flavor when roasted.",
        "base experience": 1,
    ]),
    "hazelnut": ([
        "type": "nut",
        "subtype": "hazel",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Small, round nuts with hard shells and sweet, oil-rich kernels. "
            "Squirrels and humans alike treasure these autumn gifts that can "
            "be eaten fresh or stored for winter sustenance.",
        "base experience": 1,
    ]),
    "rowan berry": ([
        "type": "fruit",
        "subtype": "rowan",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Bright orange-red berries growing in clusters on mountain ash "
            "trees. Though too bitter to eat fresh, they make excellent preserves "
            "and are believed to ward off evil influences.",
        "base experience": 1,
    ]),
    "linden flower": ([
        "type": "flower",
        "subtype": "linden",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Small, fragrant yellow flowers that bloom in drooping clusters. "
            "Their honey-sweet scent attracts bees while healers brew them into "
            "calming teas that soothe nerves and promote restful sleep.",
        "base experience": 1,
    ]),
    "larch cone": ([
        "type": "seed",
        "subtype": "larch",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Small, egg-shaped cones from deciduous conifers that turn golden "
            "before dropping their needles. Their unique nature among evergreens "
            "makes them symbols of change and adaptation.",
        "base experience": 1,
    ]),
    "juniper berry": ([
        "type": "fruit",
        "subtype": "juniper",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Small blue berries with waxy coating and sharp, gin-like flavor. "
            "Used to flavor spirits and preserve meats, they're also burned as "
            "incense to purify spaces of negative energies.",
        "base experience": 1,
    ]),
    "serviceberry fruit": ([
        "type": "fruit",
        "subtype": "serviceberry",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Small, dark purple berries with sweet flavor reminiscent of "
            "blueberries and almonds. These nutritious fruits were traditionally "
            "dried for winter storage by forest-dwelling peoples.",
        "base experience": 1,
    ]),
    "elderberry": ([
        "type": "fruit",
        "subtype": "elderberry",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Tiny dark purple berries growing in flat-topped clusters. Rich "
            "in healing properties, they're made into syrups and wines that "
            "strengthen the body against winter ailments.",
        "base experience": 1,
    ]),
    "elderflower": ([
        "type": "flower",
        "subtype": "elderflower",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Creamy white flowers in large, flat clusters with sweet, musty "
            "fragrance. These delicate blossoms are prized for making cordials, "
            "fritters, and traditional healing preparations.",
        "base experience": 1,
    ]),
    "hornbeam nutlet": ([
        "type": "nut",
        "subtype": "hornbeam",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Tiny, ribbed nuts attached to three-lobed bracts from trees with "
            "exceptionally hard wood. Though small, they provide valuable "
            "nutrition for woodland creatures during harsh winters.",
        "base experience": 1,
    ]),
    "fig": ([
        "type": "fruit",
        "subtype": "fig",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Soft, sweet fruits with thin skin and seed-filled interior. "
            "These ancient delicacies dry beautifully and have been treasured "
            "across civilizations for their concentrated sweetness.",
        "base experience": 1,
    ]),
    "olive": ([
        "type": "fruit",
        "subtype": "olive",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Small, oval fruits that must be cured to remove bitterness before "
            "eating. Their oil has been precious as gold throughout history, "
            "used for cooking, lighting, and sacred ceremonies.",
        "base experience": 1,
    ]),
    "pawpaw": ([
        "type": "fruit",
        "subtype": "pawpaw",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Large, tropical-tasting fruits with custard-like texture and "
            "banana-mango flavor. These unusual native treasures ripen briefly "
            "in autumn, offering exotic taste in temperate forests.",
        "base experience": 1,
    ]),
    "sassafras berry": ([
        "type": "fruit",
        "subtype": "sassafras",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Small blue berries on bright red stems with subtle spicy flavor. "
            "Birds treasure these autumn fruits while humans prefer the aromatic "
            "roots and leaves for teas and seasonings.",
        "base experience": 1,
    ]),
    "sassafras root": ([
        "type": "root",
        "subtype": "sassafras",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Aromatic roots with distinctive root beer fragrance and spicy "
            "flavor. Long used by indigenous peoples for medicine and seasoning, "
            "these roots are carefully harvested to preserve the tree.",
        "base experience": 1,
    ]),
    "redbud pod": ([
        "type": "seed",
        "subtype": "redbud",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Flat, brown seed pods that persist through winter after the tree's "
            "spectacular spring flower display fades. These pods rattle in winter "
            "winds, creating nature's own percussion section.",
        "base experience": 1,
    ]),
    "tulip tree seed": ([
        "type": "seed",
        "subtype": "tulip tree",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Winged seeds from magnificent forest giants that form cone-like "
            "clusters. These seeds spiral down from great heights like tiny "
            "helicopters seeking suitable soil for new giants.",
        "base experience": 1,
    ]),
    "white pine cone": ([
        "type": "seed",
        "subtype": "white pine",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Long, cylindrical cones with thin scales from towering evergreens. "
            "These cones release seeds on papery wings that can travel great "
            "distances on mountain winds.",
        "base experience": 1,
    ]),
    "black walnut": ([
        "type": "nut",
        "subtype": "black walnut",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Rich, flavorful nuts encased in extremely hard shells and staining "
            "green husks. These prized kernels have more intense flavor than "
            "common walnuts but require significant effort to extract.",
        "base experience": 1,
    ]),
    "scots pine cone": ([
        "type": "seed",
        "subtype": "scots pine",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Small, egg-shaped cones from hardy northern pines with distinctive "
            "orange bark. These cones mature over two years before releasing "
            "their winged seeds to establish new forests.",
        "base experience": 1,
    ]),
    "douglas fir cone": ([
        "type": "seed",
        "subtype": "douglas fir",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Distinctive hanging cones with three-pronged bracts protruding "
            "between scales. Legend says these bracts are the hind feet and "
            "tails of mice hiding within the cone.",
        "base experience": 1,
    ]),
    "fir seed": ([
        "type": "seed",
        "subtype": "fir",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Small, winged seeds released from upright fir cones. Unlike other "
            "conifers, fir cones disintegrate on the tree, releasing these "
            "seeds to spiral down like tiny maple samaras.",
        "base experience": 1,
    ]),
    "balsam fir cone": ([
        "type": "seed",
        "subtype": "balsam fir",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Purple, candle-like cones that stand upright on branches before "
            "disintegrating to release seeds. Their resinous fragrance makes "
            "them prized for holiday decorations and aromatherapy.",
        "base experience": 1,
    ]),
    "balsam resin": ([
        "type": "resin",
        "subtype": "balsam",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Clear, aromatic resin that oozes from balsam fir bark blisters. "
            "This natural balm has been used for centuries to heal wounds, "
            "seal canoes, and create waterproof coatings.",
        "base experience": 1,
    ]),
    "tamarack cone": ([
        "type": "seed",
        "subtype": "tamarack",
        "crafting prerequisites": ([
            "agriculture":(["type":"skill", "value" : 3]),
        ]),
        "default description": "Small, upright cones from the unique deciduous conifer that turns "
            "golden before dropping its needles. These cones persist through "
            "winter on bare branches like tiny wooden roses.",
        "base experience": 1,
    ]),
]);

#endif
