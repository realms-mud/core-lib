//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

protected mapping Locations = ([
    "argalach castle":([
        "name": "Argalach Castle",
        "entry point": "/lib/areas/eledhel/argalach/entry.c",
        "title": "##Count## of Argalach",
        "type": "castle"
    ]),
    "durthan castle":([
        "name": "Durthan Castle",
        "entry point": "/lib/areas/eledhel/durthan/entry.c",
        "title": "##Count## of Durthan",
        "type": "castle"
    ]),
    "eledhel trading post":([
        "name": "Eledhel Trading Post",
        "entry point": "/lib/modules/domains/trading/ports/eledhel.c",
        "type": "trading post"
    ]),
    "hillgarath trading post":([
        "name": "Hillgarath Trading Post",
        "entry point": "/lib/modules/domains/trading/ports/hillgarath.c",
        "type": "trading post"
    ]),
    "minlach trading post":([
        "name": "Minlach Trading Post",
        "entry point": "/lib/modules/domains/trading/ports/minlach.c",
        "type": "trading post"
    ]),
    "adurin trading post":([
        "name": "Adurin Trading Post",
        "entry point": "/lib/modules/domains/trading/ports/adurin.c",
        "type": "trading post"
    ]),
    "linwaeth trading post":([
        "name": "Linwaeth Trading Post",
        "entry point": "/lib/modules/domains/trading/ports/linwaeth.c",
        "type": "trading post"
    ]),
    "ethyl-tirath trading post":([
        "name": "Ethyl-Tirath Trading Post",
        "entry point": "/lib/modules/domains/trading/ports/ethyl-tirath.c",
        "type": "trading post"
    ]),
]);

protected mapping AuthoredHoldings = ([
    "house aladain":([
        "id": "house-aladain",
        "name": "House Aladain",
        "owner": "Lord and Lady Aladain",
        "allegiance": "Eledhel",
        "entry point":
            "/areas/eledhel/estates/aladain/grounds/3x4.c",
        "type": "keep"
    ]),
    "house oeldhen":([
        "id": "house-oeldhen",
        "name": "House Oeldhen",
        "owner": "House Oeldhen",
        "allegiance": "Eledhel",
        "entry point":
            "/areas/eledhel/estates/oeldhen/grounds/0x2.c",
        "type": "keep"
    ]),
    "house llenwych":([
        "id": "house-llenwych",
        "name": "House Llenwych",
        "owner": "House Llenwych",
        "allegiance": "Eledhel",
        "entry point":
            "/areas/eledhel/estates/llenwych/grounds/0x2.c",
        "type": "keep"
    ]),
    "house urdhan":([
        "id": "house-urdhan",
        "name": "House Urdhan",
        "owner": "House Urdhan",
        "allegiance": "Eledhel",
        "entry point":
            "/areas/eledhel/estates/urdhan/grounds/0x2.c",
        "type": "keep"
    ]),
    "house hador":([
        "id": "house-hador",
        "name": "House Hador",
        "owner": "House Hador",
        "allegiance": "Eledhel",
        "entry point":
            "/areas/eledhel/estates/hador/grounds/0x2.c",
        "type": "keep"
    ]),
    "house endur":([
        "id": "house-endur",
        "name": "House Endur",
        "owner": "House Endur",
        "allegiance": "Eledhel",
        "entry point":
            "/areas/eledhel/estates/endur/grounds/0x2.c",
        "type": "keep"
    ]),
    "house celedrath":([
        "id": "house-celedrath",
        "name": "House Celedrath",
        "owner": "Celedrath household",
        "allegiance": "Eledhel",
        "entry point":
            "/areas/eledhel/estates/celedrath/grounds/0x2.c",
        "type": "keep"
    ])
]);
