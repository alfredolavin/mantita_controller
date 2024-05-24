#include <eduardino.hpp>

union color_t {
  u24 value;
  struct {
    u8 b,r,g; }; };

mInFlash(u24 colors[])= {
  /*1*/		0x0000FF,
  /*2*/		0x0000FF,
  /*3*/		0x0000FF,
  /*4*/		0x0000FF,
  /*5*/		0x0000FF,
  /*6*/		0x0000FF,
  /*7*/		0x0000FF,
  /*8*/		0x0000FF,
  /*9*/		0x0000FF,
  /*10*/	0x0000FF,
  /*11*/	0x0000FF,
  /*12*/	0x0000FF,
  /*13*/	0x0000FF,
  /*14*/	0x0000FF,
  /*15*/	0x0000FF,
  /*16*/	0x0000FF,
  /*17*/	0x0000FF,
  /*18*/	0x2A00FF,
  /*19*/	0x5500FF,
  /*20*/	0x7F00FF,
  /*21*/	0xAA00FF,
  /*22*/	0xD400FF,
  /*23*/	0xFF00FF,
  /*24*/	0xD42AD4,
  /*25*/	0xAA55AA,
  /*26*/	0x7F7F7F,
  /*27*/	0x55AA55,
  /*28*/	0x2AD42A,
  /*29*/	0x00FF00,
  /*30*/	0x00FF00,
  /*31*/	0x00FF00,
  /*32*/	0x00FF00,
  /*33*/	0x00FF00,
  /*34*/	0x00FF00,
  /*35*/	0x00FF00,
  /*36*/	0x2AF500,
  /*37*/	0x55EB00,
  /*38*/	0x7FE100,
  /*39*/	0xAAD700,
  /*40*/	0xD4CD00,
  /*41*/	0xFFC400,
  /*42*/	0xFF9C00,
  /*43*/	0xFF7500,
  /*44*/	0xFF4E00,
  /*45*/	0xFF2700,
  /*46*/	0xFF0000 };

const u8 n_colors = countof(colors);

