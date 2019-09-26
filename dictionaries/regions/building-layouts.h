//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef building_layouts_h
#define building_layouts_h

private mapping BuildingLayouts = ([ 
    "1x1":([
        "type 1": ([
            "ascii": ({ "+-+", "| |", "+-+" }),
            "unicode": ({ "\xe2\x94\x8e\xe2\x8b\x82\xe2\x94\x92",
                "\xe2\x94\x83\xe2\x8b\x83\xe2\x94\x83",
                "\xe2\x94\x97\xe2\x95\xa7\xe2\x94\x9b" })
        ]),
        "type 2": ([
            "ascii": ({ "+-+", "| |", "+-+" }),
            "unicode": ({ "\xe2\x94\x8e\xe2\x95\x90\xe2\x94\x92",
                "\xe2\x94\x83\xe2\x96\xaf\xe2\x94\x83",
                "\xe2\x94\x97\xe2\x95\x90\xe2\x94\x9b" })
        ]),
        "type 3": ([
            "ascii": ({ "/-\\", "| |", "\\-/" }),
            "unicode": ({ "  \xe2\x97\xb0",
                "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x97",
                "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x9d" })
        ]),
        "type 4": ([
            "ascii": ({ "/\\ ", "|| ", "\\/ " }),
            "unicode": ({ "\xe2\x94\x8f\xe2\x94\x93\xe2\x97\xb0",
                "\xe2\x94\x83\xe2\x94\x83 ",
                "\xe2\x94\x97\xe2\x94\x9b " })
        ]),
        "type 5": ([
            "ascii": ({ "/\\ ", "||o", "\\/ " }),
            "unicode": ({ "\xe2\x94\x8c\xe2\x94\x90 ",
                "\xe2\x94\x82\xe2\x94\x82\xe2\x97\xb0",
                "\xe2\x94\x94\xe2\x94\x98 " })
        ]),
        "type 6": ([
            "ascii": ({ "/\\ ", "| \\", "\\_/" }),
            "unicode": ({ "\xe2\x94\x8c\xe2\x94\x90\xe2\x96\xad",
                "\xe2\x94\x82\xe2\x94\x94\xe2\x94\x90",
                "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x98" })
        ]),
        "type 7": ([
            "ascii": ({ "++ ", "| +", "+_+" }),
            "unicode": ({ "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x90",
                "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x98",
                "  \xe2\x96\xad", })
        ]),
        "type 8": ([
            "ascii": ({ "+-+", ": :", "+-+" }),
            "unicode": ({ "\xe2\x94\x8c\xe2\x95\x90\xe2\x94\x90",
                "\xe2\x94\x82\xe2\x96\xaf\xe2\x94\x82",
                "\xe2\x94\x94\xe2\x95\x90\xe2\x94\x98" })
        ]),
        "type 9": ([
            "ascii": ({ "+-+", "( )", "+-+" }),
            "unicode": ({ "\xe2\x95\xad\xe2\x95\xa5\xe2\x95\xae",
                "\xe2\x94\x82 \xe2\x94\x82",
                "\xe2\x95\xb0\xe2\x95\xa8\xe2\x95\xaf" })
        ]),
    ])
]);

#endif
