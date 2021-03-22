//Eventos de los inputs y textareas


const datos = {
    nombre: '',
    telefono: '',
    correo: '',
    mensaje: ''
};

const nombre = document.querySelector('#nombre');
const telefono = document.querySelector('#telefono');
const correo = document.querySelector('#correo');
const mensaje = document.querySelector('#mensaje');
const formulario = document.querySelector('.formulario');
let cerrar = document.querySelector('.close');
let abrir = document.querySelector('#enviar');
let modal1 = document.querySelector('.exito');
let modal2 = document.querySelector('.error');
let close = document.querySelector('.cerrar');



nombre.addEventListener('input', leerTexto);
telefono.addEventListener('input', leerTexto);
correo.addEventListener('input', leerTexto);
mensaje.addEventListener('input', leerTexto);

//El evento de Submit
// formulario.addEventListener('submit', function(e){
//     e.preventDefault();

    //Validar el formulario
    

    
    abrir.addEventListener('click', function(e){
        e.preventDefault();

        const {nombre, email, mensaje} = datos;

        close.style.opacity = '1';
        close.style.visibility = 'visible';
        if(nombre === '' || email === '' || telefono === '' || mensaje === ''){
            modal2.classList.toggle('ventana__error');
            // mostrarAlerta('Todos los campos son Obligatorios', true);
            cerrar.addEventListener('click', function(e){
                e.preventDefault();
                close.style.opacity = '0';
                close.style.visibility = 'hidden';
                modal2.classList.toggle('ventana__error');
            });
        }
        if(nombre != '' & email != '' & telefono != '' & mensaje != ''){
            modal1.classList.toggle('ventana__exito');
            cerrar.addEventListener('click', function(e){
                e.preventDefault();
                close.style.opacity = '0';
                close.style.visibility = 'hidden';
                modal1.classList.toggle('ventana__exito');
            });
        }
        
    })
    
    // mostrarAlerta('Formulario Enviado Correctamente');
    
// });


function leerTexto(e){
    datos[e.target.id] = e.target.value
    // console.log(datos);
}

// function mostrarAlerta(mensaje, error = null){
//     const alerta = document.createElement('P');
//     alerta.textContent = mensaje
//     if(error){
//         alerta.classList.add('error');
//     } else{
//         alerta.classList.add('exito');
//     }
//     formulario.appendChild(alerta);
//     //desaparezca
//     setTimeout(() =>{
//         alerta.remove();
//     }, 2000);
// }

//-----------------------------------------------------------------------------------//

//Eventos en página sobre mi

const act = document.getElementsByClassName("tool");
var i;

for(i = 0; i < act.length; i++){
    act[i].onclick = function(){
        this.classList.toggle("active");
        this.nextElementSibling.classList.toggle("show");
    }
}

//--------------------NAVEGACION----------------------------------------------------------//

let menuToggle = document.querySelector('.menu-toggle');
let menuToggleIcon = document.querySelector('.menu-toggle i');
let navegacion = document.getElementById('menu');
let enlace = document.querySelectorAll('.me');
let j;

menuToggle.addEventListener('click', e=>{
    navegacion.classList.toggle('mostrar');
    barraNavegacion();
});

for(j=0; j< enlace.length; j++){
    enlace[j].onclick = function(){
    navegacion.removeAttribute('class', 'mostrar');
    barraNavegacion();
    } 
}
function barraNavegacion(enlace){
    if(navegacion.classList.contains('mostrar')){
        menuToggleIcon.setAttribute('class', 'fa fa-times');
        
    }else{
        menuToggleIcon.setAttribute('class', 'fa fa-bars');
    }
}

//----------------------------------------------------------------------------------------//

let ref = document.getElementsByClassName('me');

ref.addEventListener('click', e=>{
    e.preventDefault();
});