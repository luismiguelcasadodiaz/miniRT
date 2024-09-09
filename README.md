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

According to this table of times in millisecond, array of doubles passed by referencia cd  float have a better performance.
