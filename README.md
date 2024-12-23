# miniRT
This project is an introduction to the beautiful world of Raytracing. Once completed you will be able to render simple Computer-Generated-Images and you will never be afraid of implementing mathematical formulas again.

> To accurately render a two-dimensional image of a three-dimensional scene, global illumination information that affects the intensity of each pixel of the image must be known at the time the intensity is calculated. In a simplified form, this information is stored in a tree of “rays” extending from the viewer to the first surface encountered and from there to other surfaces and to the light sources. A visible surface algorithm creates this tree for each pixel of the display and passes it to the shader. The shader then traverses the tree to determine the intensity of the light received by the viewer. Consideration of all of these factors allows the shader to accurately simulate true reflection, shadows, and refraction, as well as the effects simulated by conventional shaders. Anti-aliasing is included as an integral part of the visibility calculations. Surfaces displayed include curved as well as polygonal surfaces.

Turner Whitted : [**An Improved illumination model for shaded display**](https://dl.acm.org/doi/pdf/10.1145/358876.358882) Communications of the ACM June 1980 volume 23 Number 6.


|operations|Array of Doubles arg passed by ref|Array of Floats arg passed by ref|3 double escalars arg passed by ref|3 float escalars arg passed by ref|3 float escalars arg passed by copy|
|----------|----------------|---------------|-----------------|----------------|-----------------------------------|
|10 000 000|typedef struct s_vec3<br>{<br>double	e[3];<br>}	t_vec3;|typedef struct s_vec3<br>{<br>float	e[3];<br>}	t_vec3;|typedef struct s_vec3<br>{<br>double	x;<br>double	y;<br>double	z;<br>}	t_vec3;|typedef struct s_vec3<br>{<br>float	x;<br>float	y;<br>float	z;<br>}	t_vec3;|typedef struct s_vec3<br>{<br>float	x;<br>float	y;<br>float	z;<br>}	t_vec3;|
|sums | 47|60|60|58|131|
|subs | 44|65|58|58|105|
|mult | 45|47|50|52|98|
|dots | 39|39|38|38|36|
|cross|110|109|109|109|97|


According to this table of times in milliseconds, an array of doubles passed by reference cd  float performs better.


## Ambient light
An ambient light **must NOT influence** the object's color.

In the first approach, We tested it with nine images, changing ambient light intensity from 0.1 to 0.9 in 0.1 steps. First, we tested  with a plane. Second, we tested with a sphere


![Screenshot from 2024-11-21 20-31-08](https://github.com/user-attachments/assets/c0787ff9-4004-4a14-a4cb-07822e26ee19)


![Screenshot from 2024-11-21 20-45-43](https://github.com/user-attachments/assets/dde7d562-05f3-4f3c-8ae0-9cf25a68f606)


However, the discussion with 42 peers showed our approach was wrong. We change it to impact only the background color.


Starting with a black background color, increasing blue ambient light intensity produces this image.

![Blue_ambient_light](https://github.com/user-attachments/assets/bb216abd-bbb3-4c7b-8593-22f24e8ab4e7)

Testing with red ambient light, we got.

![Red_ambient_light](https://github.com/user-attachments/assets/3bf48351-2d54-4f55-a90e-a86467299ed8)


![Blue_red_balls_Without_Antialiasing](https://github.com/user-attachments/assets/ae08081b-dee2-4785-80c0-0fba88d6eb5b)


![Blue_red_balls_With_20_Antialiasing](https://github.com/user-attachments/assets/b4fa9e51-1ad3-4098-b882-48136166e657)



![Antialiasing comparison](https://github.com/user-attachments/assets/984d284a-55a3-41bd-82d8-3d84b576f51e)
![FOV_test](https://github.com/user-attachments/assets/be69eef7-6c4a-4313-bef0-8abbd4fe8a89)

![Evaluacion_Semiesferas](https://github.com/user-attachments/assets/23a9890e-1971-4d02-848d-fc6d77d279aa)
![four_cyl_one_sphere1](https://github.com/user-attachments/assets/21a4bfb4-ba92-4443-bcb3-91a516404ef3)
![four_cyl_one_sphere2](https://github.com/user-attachments/assets/65f1bdd1-91aa-4cb6-b153-9a8583dbea94)


![espirales](https://github.com/user-attachments/assets/56181c58-a29a-4abc-976c-a1956267841d)
![Screenshot from 2024-12-11 14-02-31](https://github.com/user-attachments/assets/2a7f0677-3c9c-43e9-afc9-a3ec6ec314f9)




## Camera setup

01.- self->coor=coor

02.- self->novec= novec_unit

03.- self->hfov = hfov;

04.- self->aspect_ratio = ASPECT_RATIO_W / ASPECT_RATIO_H

05.- self->image_width = WINDOW_W

06.- self->image_height = self->image_width / self->aspect_ratio

07.- self->samples_per_pixel = 20

08.- self->max_depth = 10

09.- self->vfov = hfov

10.- self->pixel_samples_scale = 1.0 / self->samples_per_pixel

11.- self->lookfrom = self->coor

12.- self->lookat = self->lookfrom + self->novec

13.- self->vup = (0,1,0)

14.- self->focal_lenght = length(self->coor)

15.- self->theta = (self->vfov * M_PI) / 180.0

16.- self->h = tan(self->theta / 2)

17.- self->viewport_height = 2 * self->h * self->focal_lenght;

18.- self->viewport_width = self->viewport_height * ((double)self->image_width / self->image_height)

19.- self->w = novec_unit

20.- self->u = self->w cross self->vup

21.- self->v = self->w cross &self->u

22.- self->vp_v = -(self->v) times self->viewport_height

23.- self->vp_u =  &self->u, self->viewport_width

24.- self->pd_u = self->vp_u / self->image_width

25.- self->pd_v = self->vp_v / self->image_height

26.- self->vp_ul = self->center - ((self->vp_u / 2) + (self->vp_v / 2) + (self->w times self->focal_lenght))

27.- self->pixel00_loc = &self->vp_ul + (self->pd_u + self->pd_v) / 2

28.- self->color_start, 0.5, 0.7, 0.5;

29.- self->color_end, 0.0, 0.0, 0.0;



## Camera set new hvof



03.- self->hfov = hfov;

09.- self->vfov = hfov

15.- self->theta = (self->vfov * M_PI) / 180.0

16.- self->h = tan(self->theta / 2)

17.- self->viewport_height = 2 * self->h * self->focal_lenght;

18.- self->viewport_width = self->viewport_height * ((double)self->image_width / self->image_height)

22.- self->vp_v = -(self->v) times self->viewport_height

23.- self->vp_u =  &self->u, self->viewport_width

24.- self->pd_u = self->vp_u / self->image_width

25.- self->pd_v = self->vp_v / self->image_height

26.- self->vp_ul = self->center - ((self->vp_u / 2) + (self->vp_v / 2) + (self->w times self->focal_lenght))

27.- self->pixel00_loc = &self->vp_ul + (self->pd_u + self->pd_v) / 2





## Camera set new focal lenght





14.- self->focal_lenght = length(self->coor)

17.- self->viewport_height = 2 * self->h * self->focal_lenght;

18.- self->viewport_width = self->viewport_height * ((double)self->image_width / self->image_height)

22.- self->vp_v = -(self->v) times self->viewport_height

23.- self->vp_u =  &self->u, self->viewport_width

24.- self->pd_u = self->vp_u / self->image_width

25.- self->pd_v = self->vp_v / self->image_height

26.- self->vp_ul = self->center - ((self->vp_u / 2) + (self->vp_v / 2) + (self->w times self->focal_lenght))

27.- self->pixel00_loc = &self->vp_ul + (self->pd_u + self->pd_v) / 2



## GDB

I found very convenient conditional breapoint in this project.
It help me to stop the execution at object hitting coordinates to explore this
part of code.

```gdb
break is_scene4.c:71 if ((wy0 == 300) && (wx0 ==600))
```
I combined it with `info break` and `disable/enable break n` to 
activate/desactivate breakppoitns at convenience.
