private nosave mapping fighterBlueprints = ([
    "swordsman":([
        "description": "A swordsman stands tall and poised, clad in well-fitted armor that "
            "gleams with polish. Their hands are calloused, and their posture is "
            "confident, with a sword always at their side. Their gaze is sharp, and "
            "their movements are precise and measured.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger",
            "two-handed sword", "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "swords" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "man-at-arms":([
        "description": "A man-at-arms is broad-shouldered and sturdy, wearing a mix of "
            "chainmail and plate. Their armor is practical and well-worn, often "
            "bearing the marks of many battles. They carry a variety of weapons, and "
            "their face is often set in a determined expression.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger", "axe",
            "two-handed sword", "plate armor", "splint armor", "mace",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "swords", "axes", "maces" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 150,
        "base spell points": 10,
        "base stamina points": 75
    ]),
    "knifeman":([
        "description": "A knifeman is lean and agile, dressed in close-fitting leathers or "
            "light mail. Several daggers are strapped to their belt and boots, and "
            "their eyes dart about with a wary, calculating look. Their hands are "
            "quick, and their stance is always ready to spring into action.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "short sword", "dagger",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "daggers" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "light infantry": ([
        "description": "Light infantry wear supple leather or simple mail, allowing for "
            "freedom of movement. Their gear is practical and minimal, and their "
            "faces are often sun-browned and alert. They carry swords or daggers, "
            "and their boots are worn from long marches.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger",
            "two-handed sword", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter", "infantry" }),
        "equipment": ([ 
            "weapons":({ "daggers", "swords" }),
            "armor": ({ "light-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "axeman":([
        "description": "An axeman is powerfully built, with muscular arms and a heavy axe "
            "resting on one shoulder. Their armor is reinforced and often bears "
            "nicks and scars from battle. Their beard may be thick, and their hands "
            "are large and calloused.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "axe", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "axes" }),
            "armor": ({ "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "maceman":([
        "description": "A maceman is stocky and solid, clad in sturdy armor with a heavy "
            "mace hanging from their belt. Their arms are thick, and their knuckles "
            "are often bruised. Their helmet is dented, and their expression is "
            "grim and resolute.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "mace", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "maces" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "hammerman":([
        "description": "A hammerman is broad and imposing, with a massive warhammer slung "
            "across their back. Their armor is reinforced at the shoulders and arms, "
            "and their boots are heavy. Their jaw is set, and their eyes are steely "
            "with focus.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "hammer", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "hammers" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "flail man":([
        "description": "A flail man is clad in heavy armor, with a spiked flail hanging "
            "from their belt. Their gauntlets are reinforced, and their helmet is "
            "often adorned with a crest. Their stance is balanced, and their eyes "
            "watch for any opening.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "flail", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "aliases": ({ "fighter", "man" }),
        "potential traits": ({ }),
        "equipment": ([ 
            "weapons":({ "flails" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "staff man":([
        "description": "A staff man is tall and wiry, dressed in simple robes or light "
            "armor. They carry a long staff, often carved or adorned, and their "
            "movements are fluid and controlled. Their eyes are calm, and their "
            "stance is relaxed but ready.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "staff", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter", "man" }),
        "equipment": ([ 
            "weapons":({ "staffs" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "halberdier":([
        "description": "A halberdier is tall and disciplined, clad in heavy armor with a "
            "long halberd held upright. Their armor is polished, and their helmet "
            "often sports a plume. Their posture is straight, and their gaze is "
            "forward and unwavering.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "pole arm", 
            "plate armor", "splint armor", "chainmail", "scalemail" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "pole-arms/halberd" }),
            "armor": ({ "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "spearman":([
        "description": "A spearman is lean and athletic, dressed in light or medium armor. "
            "They carry a long spear, and their shield is strapped to one arm. Their "
            "stance is balanced, and their eyes are alert, scanning for threats.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "pole arm", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "pole-arms/spear" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helmet", "ring" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "guisarmier":([
        "description": "A guisarmier is tall and imposing, clad in a mix of mail and plate. "
            "They wield a long polearm with a hooked blade, and their armor is "
            "decorated with insignia. Their stance is disciplined, and their eyes are "
            "focused on the battlefield.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "pole arm", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "pole-arms" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "brawler":([
        "description": "A brawler is rugged and muscular, often bare-armed or wearing only "
            "simple armor. Their knuckles are scarred, and their nose may be crooked "
            "from old breaks. Their stance is loose and ready, with a confident grin.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "unarmed", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "archer":([
        "description": "An archer is slender and keen-eyed, dressed in light armor or "
            "leathers. A quiver of arrows is slung across their back, and a bow is "
            "always within reach. Their fingers are calloused, and their gaze is "
            "focused on distant targets.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "bow", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "bowyer and fletcher" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "bows" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "crossbowman":([
        "description": "A crossbowman is sturdy and practical, wearing medium armor and "
            "carrying a heavy crossbow. Their belt is lined with bolts, and their "
            "hands are strong and steady. Their eyes are narrowed, always searching "
            "for a vantage point.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "crossbow", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "bowyer and fletcher" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "crossbows" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "auxiliary":([
        "description": "An auxiliary is lightly armored, with a sling or throwing weapons "
            "at their side. Their clothing is practical, and their boots are worn "
            "from travel. They have a ready, alert look and move with quick, "
            "efficient motions.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "sling", 
            "thrown", "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "bowyer and fletcher" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "thrown", "slings" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "knight": ([
        "description": "A knight is imposing and regal, clad in gleaming plate armor "
            "adorned with heraldic symbols. Their helmet is crested, and their "
            "posture is upright and proud. A sword or mace hangs at their side, and "
            "their cloak is often trimmed with fine embroidery.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger", "axe",
            "two-handed sword", "plate armor", "splint armor", "mace",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "swords", "axes", "maces" }),
            "armor": ({ "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 150,
        "base spell points": 100,
        "base stamina points": 50
    ]),
    "phaedra": ([
        "description": "A phaedra is a striking figure in ornate, masterfully crafted armor. "
            "Their cloak is richly colored, and their helm is adorned with intricate "
            "designs. Their bearing is noble, and their eyes reflect both wisdom and "
            "resolve.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger", "axe",
            "two-handed sword", "plate armor", "splint armor", "mace",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter", "knight" }),
        "equipment": ([ 
            "weapons":({ "swords", "axes", "maces" }),
            "armor": ({ "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 200,
        "base spell points": 100,
        "base stamina points": 100
    ]),
    "knight of the storm":([
        "description": "A knight of the storm is clad in armor etched with swirling "
            "patterns, often accented with blue or silver. Their cloak billows as if "
            "caught in a breeze, and their eyes flash with intensity. Their presence "
            "is commanding, and their armor gleams with a faint, electric sheen.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger",
            "two-handed sword", "plate armor", "splint armor",
            "chainmail", "scalemail", "elemental air" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield", "magical essence",
            "spellcraft", "evocation" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter", "knight", "storm" }),
        "equipment": ([ 
            "weapons":({ "swords" }),
            "armor": ({ "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "research": ([
            "lightning": 1,
        ]),
        "base hit points": 150,
        "base spell points": 100,
        "base stamina points": 50
    ]),
]);
