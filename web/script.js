function actualizarDatos() {
    const nivel = Math.floor(Math.random() * (150 - 50) + 50);
    const turbidez = (Math.random() * 10).toFixed(2);
    
    document.getElementById('nivel').textContent = nivel + ' cm';
    document.getElementById('turbidez').textContent = turbidez + ' NTU';
}

setInterval(actualizarDatos, 3000);
actualizarDatos();